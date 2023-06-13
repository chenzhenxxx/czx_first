#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netpacket/packet.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/if_ether.h>

int main()
{
    // 创建原始套接字
    int sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // 获取本地网络接口的MAC地址和IP地址
    struct ifreq ifreq;
    memset(&ifreq, 0, sizeof(ifreq));
    strncpy(ifreq.ifr_name, "wlp0s20f3", IFNAMSIZ - 1);

    if (ioctl(sock, SIOCGIFHWADDR, &ifreq) < 0) {
        perror("ioctl - SIOCGIFHWADDR");
        close(sock);
        exit(1);
    }

    unsigned char *mac_addr = (unsigned char *)ifreq.ifr_hwaddr.sa_data;
    printf("MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n",
           mac_addr[0], mac_addr[1], mac_addr[2],
           mac_addr[3], mac_addr[4], mac_addr[5]);

    if (ioctl(sock, SIOCGIFADDR, &ifreq) < 0) {
        perror("ioctl - SIOCGIFADDR");
        close(sock);
        exit(1);
    }

    struct sockaddr_in *addr = (struct sockaddr_in *)&ifreq.ifr_addr;
    printf("IP address: %s\n", inet_ntoa(addr->sin_addr));

    // 接收数据
    char buf[1024];
    while (1) {
        int len = recv(sock, buf, sizeof(buf), 0);
        if (len < 0) {
            perror("recv");
            break;
        }
        printf("Received %d bytes of data\n", len);
    }

    // 关闭套接字
    close(sock);

    return 0;
}