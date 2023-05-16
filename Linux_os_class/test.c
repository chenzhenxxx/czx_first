#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int A;
int B = 0;
int C = 2;
static int D;
static int E = 0;
static int F = 4;
const int G = 5;
const char H = 6;
int main(void)
{
    int a;
    int b = 0;
    int c = 2;
    static int d;
    static int e = 0;
    static int f = 4;
    const int g = 5;

    char char1[] = "abcde";
    char *cptr = "123456";
    // 局部字符数组//p在栈上，13456在常量区
    int *heap = malloc(sizeof(int) * 4); // 堆
    printf("PID is :%d\n\n", getpid());
    printf("int A           A_addr = %p\n", &A);
    printf("int B=0         B_addr = %p\n", &B);
    printf("int C=0         C_addr = %p\n", &C);
    printf("static int D        D_addr = %p\n", &D);
    printf("static int E = 0    E_addr = %p\n", &E);
    printf("static int F = 4    F_addr = %p\n", &F);
    printf("const  int G = 5    G_addr = %p\n", &G);
    printf("const char H = 6    H_addr = %p\n", &H);
    printf("\n");
    printf("int A           A_addr = %p\n", &a);
    printf("int B=0         B_addr = %p\n", &b);
    printf("int C=0         C_addr = %p\n", &c);
    printf("static int D        D_addr = %p\n", &d);
    printf("static int E = 0    E_addr = %p\n", &e);
    printf("static int F = 4    F_addr = %p\n", &f);
    printf("const  int G = 5    G_addr = %p\n", &g);
    printf("\n");
    printf("char char1[] = 'abcde'\t\t\tchar1_addr = %p\n", char1);
    printf("char char1[] = 'abcde'\t\t\tchar1_addr = %p\n", &char1);
    printf("char *cptr[] = '1'\t\t\tcptr_addr = %p\n", &cptr);
    printf("value of the cptr\t\t\tcptr_value = 0x%p\n", cptr);
    printf("value of %p\t\t\tvalue_0x%p = %d\n", cptr, cptr, *cptr);
    printf("int* heap = malloc(sizeof(int)*4)\theap_addr = %p\n",heap);
    printf("int* heap = malloc(sizeof(int)*4)\t&heap_addr = %p\n", &heap);
    pause();
    free(heap);
    return 0;
}