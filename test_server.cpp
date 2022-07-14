#include "Msg.h"
#include "NetworkTest.grpc.pb.h"
#include "NetworkTest.pb.h"
#include <algorithm>
#include <arpa/inet.h>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <grpc/grpc.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <grpcpp/support/status.h>
#include <grpcpp/support/status_code_enum.h>
#include <memory>
#include <mutex>
#include <string.h>
#include <string>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <thread>
#include <unordered_map>
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
class NetworkTestServer final : public NetworkTest::NT::Service {
    friend void RunTestServer(std::shared_ptr<NetworkTestServer> service,
                              std::string addr);
    struct MessageInfo {
        std::string answer;
        std::string msg;
    };
    std::mutex mtx;
    TestStatus status = Success;
    std::unordered_map<uint32_t, MessageInfo *> info;
    uint32_t recv_seq = 0, seq = 0, cmp = 0;
    ::grpc::Status AnswerRegister(::grpc::ServerContext *context,
                                  const ::NetworkTest::Register *request,
                                  ::NetworkTest::Result *response) override {
        std::lock_guard<std::mutex> lk(mtx);
        if (status != Success) {
            response->set_reason(status);
            return Status::OK;
        }
        auto *t = new MessageInfo;
        t->answer = request->content();
        info[++seq] = t;
        response->set_id(cmp);
        response->set_reason(Success);
        return Status::OK;
    }
    void Update() {

        if (status != Success)
            return;

        auto avaliableMaxResult = std::min(recv_seq, seq);

        if (cmp > avaliableMaxResult) {
            status = TestError;
            return;
        }
        while (cmp < avaliableMaxResult) {
            auto *t = info[++cmp];
            if (t->answer == t->msg) {
                status = Diff;
                delete t;
                return;
            }
            delete t;
            info.erase(cmp);
        }
    }

    ::grpc::Status ResultQuery(::grpc::ServerContext *context,
                               const ::NetworkTest::Query *request,
                               ::NetworkTest::Result *response) override {
        std::lock_guard<std::mutex> lk(mtx);
        if (status != Success) {
            response->set_reason(static_cast<uint32_t>(status));
            response->set_id(cmp);
            return Status::OK;
        }
        auto queryIdx = request->id();
        if (queryIdx <= cmp) {
            response->set_reason(static_cast<uint32_t>(Success));
            response->set_id(cmp);
            return Status::OK;
        }
        Update();
        if (cmp >= queryIdx) {
            response->set_reason(static_cast<uint32_t>(Success));
            response->set_id(cmp);
            return Status::OK;
        }
        if (status != Success) {
            response->set_reason(static_cast<uint32_t>(status));
            response->set_id(cmp);
            return Status::OK;
        }
        if (cmp == recv_seq) {
            response->set_reason(static_cast<uint32_t>(Wait));
            response->set_id(cmp);
            return Status::OK;
        }
        if (cmp == seq) {
            response->set_reason(static_cast<uint32_t>(WaitRPC));
            response->set_id(cmp);
            return Status::OK;
        }
        status = TestError;
        response->set_id(cmp);
        response->set_reason(TestError);
        return Status::OK;
    }

public:
    void commit(std::string &&msg) {
        printStr(msg);
        std::lock_guard<std::mutex> lk(mtx);
        if (status != Success) {
            return;
        }
        if (info[++recv_seq] == nullptr) {
            info[recv_seq] = new MessageInfo;
        }
        auto *t = info[recv_seq];
        t->msg = std::move(msg);
    }
};

void RunTestServer(std::shared_ptr<NetworkTestServer> service,
                   std::string addr) {
    ServerBuilder builder;
    builder.AddListeningPort(addr, grpc::InsecureServerCredentials());
    builder.RegisterService(service.get());
    std::unique_ptr<Server> server(builder.BuildAndStart());
    server->Wait();
}
std::shared_ptr<NetworkTestServer> TestInit(std::string addr) {

    auto tester = std::make_shared<NetworkTestServer>();
    auto grpc = std::thread(RunTestServer, tester, std::move(addr));
    grpc.detach();
    return tester;
}
class mess {
public:
    int partid;
    int len;
};

struct sendd {
    ssize_t len;
    char data[0];
};
int readn(int fd, void *buf, int count) {
    int cnt = count;
    char *p = (char *) buf;
    while (cnt > 0) {
        int readbyte = read(fd, p, cnt);
        if (readbyte == 0) {
            //printf("close\n");

            break;
        } else if (readbyte < 0) {
            if (errno == EINTR) {
                continue;
            } else
                return -1;
        }
        cnt -= readbyte;
        p += readbyte;
    }
    return count - cnt;
}
pthread_mutex_t mutex;
int main() {
    // Server 端的监听地址
    //int count = 0;
    auto test = TestInit("0.0.0.0:1234");
    struct sockaddr_in svaddr;
    struct sockaddr_storage claddr;
    socklen_t addrlen;
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    int cfd;
    bzero(&svaddr, sizeof(svaddr));
    svaddr.sin_family = AF_INET;
    svaddr.sin_port = htons(5555);
    svaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(sfd, (struct sockaddr *) &svaddr, sizeof(svaddr));
    listen(sfd, 100);
    //cfd=accept(sfd,(struct sockaddr *)&claddr,&addrlen);
    int len = 0;

    int epollfd = epoll_create(5);
    if (epollfd == -1) {
        std::cout << "epoll_create error." << std::endl;
        close(sfd);
        return -1;
    }
    epoll_event ev;
    ev.data.fd = sfd;
    ev.events = EPOLLIN;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, sfd, &ev) == -1) {
        std::cout << "epoll_ctl error." << std::endl;
        close(sfd);
        return -1;
    }
    while (1) {//pthread_mutex_lock(&mutex);

        epoll_event epoll_events[4096];
        int n = epoll_wait(epollfd, epoll_events, 4096, 1000);
        if (n < 0) {
            if (errno == EINTR)//被信号中断
                continue;
            break;
        } else if (n == 0)//超时
        {
            //count++;
            continue;
        }
        //count = 0;
        for (int i = 0; i < n; i++) {
            if (epoll_events[i].events == EPOLLIN) {
                if (epoll_events->data.fd == sfd)//监听已经有输入
                {
                    struct sockaddr_in clientaddr;
                    socklen_t clientaddrlen = sizeof(clientaddr);
                    int clientfd = accept(sfd, (struct sockaddr *) &clientaddr, &clientaddrlen);
                    if (clientfd == -1) {
                        break;
                    }
                    epoll_event ev;
                    ev.data.fd = clientfd;
                    ev.events = EPOLLIN;
                    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, clientfd, &ev) == -1) {
                        std::cout << "epoll_ctl error." << std::endl;
                        close(sfd);
                        return -1;
                    }
                    std::cout << "accept a client connection,fd: " << clientfd << std::endl;
                }

                else//
                {
                    int cfd = epoll_events[i].data.fd;
                    int len = 0;
                    //struct sendd *st;
                    //memset(&st,0,sizeof(st));

                    int ret = readn(cfd, &len, 4);
                    //printf("%d\n", ret);
                    if (ret == -1) {
                        perror("read");
                        break;
                    }
                    //printf("over");


                    int databyte = ntohl(len);
                    if (databyte == 0) {
                        continue;
                    }
                    //printf("readlemn=%d\n", databyte);
                    char buf[4096];
                    int readlen = readn(cfd, buf, databyte);
                    if (readlen == 0) {
                        epoll_ctl(epollfd, EPOLL_CTL_DEL, cfd, NULL);
                        close(cfd);
                        break;
                    }
                    std::string s(buf, databyte);
                    memset(buf,0,4096);
                    test->commit(std::move(s));
                    //write(STDOUT_FILENO,buf, databyte);


                    //st=NULL;
                    //pthread_mutex_unlock(&mutex);
                }
            }
        }
    }
    close(cfd);


    // Put your code Here!
}
