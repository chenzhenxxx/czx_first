#include <stdio.h>
#include <stdlib.h>

#define MAX_MEM_SIZE 1024 // 内存大小

typedef struct node {
    int start; // 起始地址
    int end;   // 结束地址
    int size;  // 空闲块大小
    struct node *next; // 指向下一个节点的指针
} Node;

Node *freeList = NULL; // 空闲块链表

// 在空闲块链表中插入一个新节点
void insert(Node *node) {
    if (freeList == NULL) {
        freeList = node;
        return;
    }
    Node *cur = freeList;
    Node *prev = NULL;
    while (cur != NULL && cur->start < node->start) {
        prev = cur;
        cur = cur->next;
    }
    if (prev == NULL) {
        node->next = freeList;
        freeList = node;
    } else {
        node->next = prev->next;
        prev->next = node;
    }
}

// 从空闲块链表中删除一个节点
void De(Node *node) {
    if (freeList == NULL || node == NULL) {
        return;
    }
    if (freeList == node) {
        freeList = node->next;
        return;
    }
    Node *cur = freeList;
    Node *prev = NULL;
    while (cur != NULL && cur != node) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL) {
        return;
    }
    prev->next = cur->next;
}

// 初始化空闲块链表
void init() {
    Node *node1 = (Node *) malloc(sizeof(Node));
    node1->start = 0;
    node1->end = 255;
    node1->size = 256;
    node1->next = NULL;
    freeList = node1;

    Node *node2 = (Node *) malloc(sizeof(Node));
    node2->start = 256;
    node2->end = 511;
    node2->size = 256;
    node2->next = NULL;
    insert(node2);
}

// 分配一个指定大小的内存块，并返回分配的起始地址
int allocate(int size) {
    if (freeList == NULL) {
        return -1; // 内存不足
    }
    int min_size = MAX_MEM_SIZE;
    Node *best_fit = NULL;
    Node *cur = freeList;
    while (cur != NULL) {
        if (cur->size >= size && cur->size < min_size) {
            min_size = cur->size;
            best_fit = cur;
        }
        cur = cur->next;
    }
    if (best_fit == NULL) {
        return -1; // 内存不足
    }
    if (best_fit->size == size) { // 正好分配完整个空闲块
        De(best_fit);
        return best_fit->start;
    }
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->start = best_fit->start;
    new_node->end = best_fit->start + size - 1;
    new_node->size = size;
    new_node->next = NULL;
    best_fit->start += size;
    best_fit->size -= size;
    insert(new_node);
    return new_node->start;
}

// 释放已经分配的内存块
void deallocate(int start, int size) {
    int end = start + size - 1;
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->start = start;
    new_node->end = end;
    new_node->size = size;
    new_node->next = NULL;
    insert(new_node);
    Node *merge_node = freeList;
    while (merge_node != NULL) {
        if (merge_node->next != NULL && merge_node->end + 1 == merge_node->next->start) {
            merge_node->end = merge_node->next->end;
            merge_node->size += merge_node->next->size;
            De(merge_node->next);
        }
        merge_node = merge_node->next;
    }
}

// 测试程序
int main() {
    init();
    int addr1 = allocate(256);
    printf("Allocated block starting at address %d\n", addr1);
    int addr2 = allocate(128);
    printf("Allocated block starting at address %d\n", addr2);
    deallocate(addr1, 256);
    printf("Deallocated block starting at address %d\n", addr1);
    int addr3 = allocate(512);
    printf("Allocated block starting at address %d\n", addr3);
    return 0;
}
