#include <stdio.h>
#include <stdlib.h>

#define PAGE_FRAME_COUNT 3 // 定义页面数量

// 链表节点的结构体
typedef struct node {
    int value; // 值
    struct node* prev; // 前一节点指针
    struct node* next; // 后一节点指针
} Node;

Node* head = NULL; // 链表头指针
Node* tail = NULL; // 链表尾指针

// 创建一个新的节点并返回
Node* create_node(int val) {
    Node* new_node = (Node*) malloc(sizeof(Node)); // 申请内存空间
    new_node->value = val; // 设置值
    new_node->prev = NULL; // 前一节点指针置空
    new_node->next = NULL; // 后一节点指针置空
    return new_node;
}

// 将一个节点插入到链表头部
void insert_to_head(Node* node) {
    if(head == NULL) { // 如果链表为空
        head = node; // 新节点既是头节点也是尾节点
        tail = node;
    } else {
        node->next = head; // 设置新节点的后一节点为原来的头节点
        head->prev = node; // 设置原来的头节点的前一节点为新节点
        head = node; // 设置新节点为头节点
    }
}

// 将指定节点移动到链表头部
void move_to_head(Node* node) {
    if(node == head) { // 如果节点已经在头部
        return; // 直接返回
    }
    if(node == tail) { // 如果节点在尾部
        tail = node->prev; // 设置新的尾部为原来的前一节点
        tail->next = NULL; // 将新的尾部节点指向空
    } else { // 如果节点在链表中间
        node->prev->next = node->next; // 设置前一节点的后一节点为当前节点的后一节点
        node->next->prev = node->prev; // 设置后一节点的前一节点为当前节点的前一节点
    }
    node->prev = NULL; // 将当前节点的前一节点置空，因为是将其移动到头部
    node->next = head; // 将当前节点的后一节点设置为原来的头节点
    head->prev = node; // 将原来的头节点的前一节点设置为当前节点
    head = node; // 将当前节点设置为头节点
}

// 删除链表尾部节点
void remove_tail() {
    if(tail != NULL) { // 如果链表不为空
        Node* temp = tail; // 暂存尾部节点
        tail = tail->prev; // 将当前节点的前一节点作为新的尾部节点
        if(tail == NULL) { // 如果此时链表为空
            head = NULL; // 头部节点置空
        } else {
            tail->next = NULL; // 新的尾部节点的下一个节点设置为空
        }
        free(temp); // 释放暂存的尾部节点内存
    }
}

// 打印链表状态（用于调试）
void print_list() {
    printf("List: "); // 输出提示信息
    Node* cur = head; // 从头节点开始遍历
    while(cur != NULL) { // 遍历整个链表
        printf("%d ", cur->value); // 输出当前节点的值
        cur = cur->next; // 移动到下一节点
    }
    printf("\n"); // 输出换行符
}

// 模拟LRU算法
void simulate_lru(int page_refs[], int ref_count) {
    int hit_count = 0; // 命中次数
    int miss_count = 0; // 缺页次数
    for(int i = 0; i < ref_count; i++) { // 遍历页面引用序列
        Node* cur = head; // 从头节点开始遍历
        while(cur != NULL) { // 遍历整个链表
            if(cur->value == page_refs[i]) { // 如果找到了要访问的页面
                move_to_head(cur); // 将它移动到链表头部
                hit_count++; // 命中次数加1
                break; // 直接退出循环
            }
            cur = cur->next; // 继续遍历下一个节点
        }
        if(cur == NULL) { // 如果整个链表都未找到
            Node* new_node = create_node(page_refs[i]); // 创建新节点
            insert_to_head(new_node); // 将新节点插入到链表头部
            miss_count++; // 缺页次数加1
            if(miss_count > PAGE_FRAME_COUNT) { // 如果链表已满
                remove_tail(); // 将尾部节点删除
                miss_count--; // 缺页次数减1
            }
        }
        print_list(); // 打印链表状态（用于调试）
    }
    printf("Hit count: %d\n", hit_count); // 输出命中次数
    printf("Miss count: %d\n", miss_count); // 输出缺页次数
}

// 主函数
int main() {
    int page_refs[] = {1, 2, 3, 4, 5, 1, 2, 6, 7, 8, 7, 8, 9, 3, 4, 5, 6, 9}; // 页面引用序列
    int ref_count = sizeof(page_refs) / sizeof(int); // 页面引用次数
    simulate_lru(page_refs, ref_count); // 模拟LRU算法
    return 0; // 结束程序
}
