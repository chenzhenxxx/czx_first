#include <stdio.h>
#define MAX 50

struct process{
    int id, at, bt, ct, wt, tat; // 进程属性：编号，到达时间，需要的CPU时间，完成时间，等待时间，周转时间
};

// 创建进程列表和队列
struct process plist[MAX];
struct queue{
    int data[MAX], front, rear;
};
struct queue q[5];
int n;

// 初始化队列
void init(struct queue *q){
    q->front = q->rear = -1;
}

// 判断队列是否为空
int isempty(struct queue *q){
    return (q->front == -1 && q->rear == -1) ? 1 : 0;
}

// 将数据插入队列尾部
void enqueue(struct queue *q, int x){
    if(isempty(q)){
        q->front = q->rear = 0;
        q->data[q->rear] = x;
    } else {
        q->rear++;
        q->data[q->rear] = x;
    }
}

// 从队列头部删除一个元素并返回值
int dequeue(struct queue *q){
    int x = q->data[q->front];
    if(q->front == q->rear){
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return x;
}

// 按照到达时间排序
void sort_arrival(){
    struct process temp;
    int i, j;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(plist[j].at > plist[j+1].at){
                temp = plist[j];
                plist[j] = plist[j+1];
                plist[j+1] = temp;
            }
        }
    }
}

// 初始化进程列表
void init_process(){
    int i;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("\nEnter details of process[%d]", i+1);
        plist[i].id = i+1;
        printf("\nArrival Time:");
        scanf("%d", &plist[i].at);
        printf("Burst Time:");
        scanf("%d", &plist[i].bt);

        // 初始化其它属性值为0
        plist[i].ct = 0;
        plist[i].wt = 0;
        plist[i].tat = 0;

        if(plist[i].bt <= 4){
            enqueue(&q[0], i);
        } else {
            enqueue(&q[1], i);
        }
    }
}

// 执行多级反馈队列调度算法并打印输出结果
void execute_mfq(){
    int time = 0, quantum = 4, i, j, k;
    while(!isempty(&q[0]) || !isempty(&q[1]) || !isempty(&q[2]) || !isempty(&q[3]) || !isempty(&q[4])){
        if(!isempty(&q[0])){
            i = dequeue(&q[0]);
            if(plist[i].bt <= quantum){
                time += plist[i].bt;
                plist[i].bt = 0;
                plist[i].ct = time;
                plist[i].tat = plist[i].ct - plist[i].at;
                plist[i].wt = plist[i].tat - (time - plist[i].at);
            } else {
                time += quantum;
                plist[i].bt -= quantum;
                for(j=0; j<n; j++){
                    if(plist[j].at <= time && plist[j].bt > 0 && i != j){
                        enqueue(&q[1], j);
                    }
                }
                enqueue(&q[2], i);
            }
        } else if(!isempty(&q[1])){
            i = dequeue(&q[1]);
            if(plist[i].bt <= quantum){
                time += plist[i].bt;
                plist[i].bt = 0;
                plist[i].ct = time;
                plist[i].tat = plist[i].ct - plist[i].at;
                plist[i].wt = plist[i].tat - (time - plist[i].at);
            } else {
                time += quantum;
                plist[i].bt -= quantum;
                for(j=0; j<n; j++){
                    if(plist[j].at <= time && plist[j].bt > 0 && i != j){
                        enqueue(&q[2], j);
                    }
                }
                enqueue(&q[3], i);
            }
        } else if(!isempty(&q[2])){
            i = dequeue(&q[2]);
            if(plist[i].bt <= quantum){
                time += plist[i].bt;
                plist[i].bt = 0;
                plist[i].ct = time;
                plist[i].tat = plist[i].ct - plist[i].at;
                plist[i].wt = plist[i].tat - (time - plist[i].at);
            } else {
                time += quantum;
                plist[i].bt -= quantum;
                for(j=0; j<n; j++){
                    if(plist[j].at <= time && plist[j].bt > 0 && i != j){
                        enqueue(&q[3], j);
                    }
                }
                enqueue(&q[4], i);
            }
        } else if(!isempty(&q[3])){
            i = dequeue(&q[3]);
            if(plist[i].bt <= quantum){
                time += plist[i].bt;
                plist[i].bt = 0;
                plist[i].ct = time;
                plist[i].tat = plist[i].ct - plist[i].at;
                plist[i].wt = plist[i].tat - (time - plist[i].at);
            } else {
                time += quantum;
                plist[i].bt -= quantum;
                enqueue(&q[4], i);
            }
        } else if(!isempty(&q[4])){
            i = dequeue(&q[4]);
            time += plist[i].bt;
            plist[i].bt = 0;
            plist[i].ct = time;
            plist[i].tat = plist[i].ct - plist[i].at;
            plist[i].wt = plist[i].tat - (time - plist[i].at);
        }

        // 将新进程按照其到达时间插入队列
        for(k=0; k<n; k++){
            if(plist[k].at == time && plist[k].bt > 0){
                if(plist[k].bt <= 4){
                    enqueue(&q[0], k);
                } else {
                    enqueue(&q[1], k);
                }
            }
        }
    }
}

// 打印结果
void print_result(){
    int avg_wt = 0, avg_tat = 0, i;
    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT");
    for(i=0; i<n; i++){
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d", plist[i].id, plist[i].at, plist[i].bt, plist[i].ct, plist[i].tat, plist[i].wt);
        avg_wt += plist[i].wt;
        avg_tat += plist[i].tat;
    }
    printf("\nAverage Waiting Time:%d", avg_wt/n);
    printf("\nAverage Turnaround Time:%d\n", avg_tat/n);
}

// 主函数
int main(){
    init_process();
    sort_arrival();
    execute_mfq();
    print_result();
    return 0;
}
