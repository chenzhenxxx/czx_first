#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 1000
#define ElementType int
typedef struct
{
    int row;
    int col;
    ElementType value;
} Triple;
typedef struct
{
    Triple data[MAXSIZE + 1];
    int row, col, nums;
} TSMarix;

void TransposeTSMatrix()
{
    int tmp = 0;
    TSMarix A;
    TSMarix B;
    A.nums = 1;
    printf("请输入数组行数：");
    scanf("%d", &A.row);
    printf("请输入数组列数：");
    scanf("%d", &A.col);
    printf("请输入数据：！\n");
    for (int i = 1; i <= A.row; i++)
        for (int j = 1; j <= A.col; j++)
        {
            scanf("%d", &tmp);
            if (tmp != 0)
            {
                A.data[A.nums].value = tmp;
                A.data[A.nums].row = i;
                A.data[A.nums].col = j;
                A.nums++;
            }
        }

    int num[MAXSIZE], pos[MAXSIZE];
    int count = 1;
    B.col = A.row;
    B.row = A.col;
    B.nums = A.nums;
    for (int i = 1; i <= A.col; i++)
    {
        num[i] = 0;
    }
    for (int j = 1; j < A.nums; j++)
    {
        num[A.data[j].col]++;
    }
    pos[1] = 1;
    for (int i = 2; i < A.nums; i++)
    {
        pos[i] = pos[i - 1] + num[i - 1];
    }
    while (count < A.nums)
    {
        int p = pos[A.data[count].col];
        B.data[p].value = A.data[count].value;
        B.data[p].col = A.data[count].row;
        B.data[p].row = A.data[count].col;
        pos[A.data[count].col]++;
        count++;
    }
    int m[B.row + 1][B.col + 1];
    memset(m, 0, sizeof(m));
    for (int i = 1; i < B.nums; i++)
    {
        m[B.data[i].row][B.data[i].col] = B.data[i].value;
    }
    for (int i = 1; i <= B.row; i++)
    {
        for (int j = 1; j <= B.col; j++)
        {
            printf("%2d", m[i][j]);
        }
        printf("\n");
    }
}
void Add()
{
    int row_a, row_b, col_a, col_b;
    int tmp = 0;
    printf("请输入A矩阵行数：\n");
    scanf("%d", &row_a);
    printf("请输入A矩阵列数:\n");
    scanf("%d", &col_a);
    int A[row_a + 1][col_a + 1];
    printf("请输入A矩阵！\n");
    for (int i = 1; i <= row_a; i++)
        for (int j = 1; j <= col_a; j++)
        {
            scanf("%d", &A[i][j]);
        }
    printf("请输入B矩阵行数：\n");
    scanf("%d", &row_b);
    printf("请输入B矩阵列数:\n");
    scanf("%d", &col_b);
    if (row_b != row_a || col_a != col_b)
    {
        printf("A,B矩阵行列数不一致，无法相加！\n");
        return;
    }
    printf("请输入B矩阵！\n");
    for (int i = 1; i <= row_b; i++)
        for (int j = 1; j <= col_b; j++)
        {
            scanf("%d", &tmp);
            A[i][j] += tmp;
        }
    printf("A+B=\n");
    for (int i = 1; i <= row_a; i++)
    {
        for (int j = 1; j <= col_a; j++)
        {
            printf("%2d", A[i][j]);
        }
        printf("\n");
    }
}
void Subtraction()
{

    int row_a, row_b, col_a, col_b;
    int tmp = 0;
    printf("请输入A矩阵行数：\n");
    scanf("%d", &row_a);
    printf("请输入A矩阵列数:\n");
    scanf("%d", &col_a);
    int A[row_a + 1][col_a + 1];
    printf("请输入A矩阵！\n");
    for (int i = 1; i <= row_a; i++)
        for (int j = 1; j <= col_a; j++)
        {
            scanf("%d", &A[i][j]);
        }
    printf("请输入B矩阵行数：\n");
    scanf("%d", &row_b);
    printf("请输入B矩阵列数:\n");
    scanf("%d", &col_b);
    if (row_b != row_a || col_a != col_b)
    {
        printf("A,B矩阵行列数不一致，无法相减！\n");
        return;
    }
    printf("请输入B矩阵！\n");
    int B[row_b + 1][col_b + 1];
    for (int i = 1; i <= row_b; i++)
        for (int j = 1; j <= col_b; j++)
        {
            scanf("%d", &B[i][j]);
        }
    int choice = 0;
    while (1)
    {
        printf("1.A-B\n");
        printf("2.B-A\n");

        scanf("%d", &choice);
        if (choice == 1)
        {
            for (int i = 1; i <= row_a; i++)
                for (int j = 1; j <= col_a; j++)
                {
                    A[i][j] -= B[i][j];
                }
            break;
        }
        else if (choice == 2)
        {
            for (int i = 1; i <= row_a; i++)
                for (int j = 1; j <= col_a; j++)
                {
                    B[i][j] -= A[i][j];
                }
            break;
        }
        else
        {
            printf("输入非法！请重新输入\n");
            continue;
        }
    }
    if (choice == 1)
    {
        printf("A-B=\n");
    }
    else
    {
        printf("B-A=\n");
    }
    for (int i = 1; i <= row_a; i++)
    {
        for (int j = 1; j <= col_a; j++)
        {
            printf("%2d", A[i][j]);
        }
        printf("\n");
    }
}
void Multiplication()
{
    int row_a, row_b, col_a, col_b;
    int tmp = 0;
    printf("请输入A矩阵行数：\n");
    scanf("%d", &row_a);
    printf("请输入A矩阵列数:\n");
    scanf("%d", &col_a);
    int A[row_a + 1][col_a + 1];
    printf("请输入A矩阵！\n");
    for (int i = 1; i <= row_a; i++)
        for (int j = 1; j <= col_a; j++)
        {
            scanf("%d", &A[i][j]);
        }
    printf("请输入B矩阵行数：\n");
    scanf("%d", &row_b);
    printf("请输入B矩阵列数:\n");
    scanf("%d", &col_b);
   
    printf("请输入B矩阵！\n");
    int B[row_b + 1][col_b + 1];
    for (int i = 1; i <= row_b; i++)
        for (int j = 1; j <= col_b; j++)
        {
            scanf("%d", &B[i][j]);
        }
    int choice = 0;
    if (row_a != col_b && row_b != col_a)
    {
        printf("两矩阵相乘无意义!\n");
        return;
    }
    while (1)
    {
        printf("1.A*B\n");
        printf("2.B*A\n");
         
        scanf("%d", &choice);
        if (choice == 1)
        {   int C[row_a+1][col_b+1];
            if (col_a != row_b)
            {
                printf("两矩阵相乘无意义!\n");
                return;
            }
            for(int i=1;i<=row_a;i++)
            for(int j=1;j<=col_b;j++)
            {  int sum=0;
               for(int k=1;k<=col_a;k++)
               {
                 sum+=A[i][k]*B[k][j];
               }
               C[i][j]=sum;
            }
            printf("A*B=\n");
            for(int i=1;i<=row_a;i++)
            {
            for(int j=1;j<=col_b;j++)
             printf("%d ",C[i][j]);
             printf("\n");
            }
            
            break;
        }
        else if (choice == 2)
        {    int C[row_b+1][col_a+1];
            if (col_b != row_a)
            {
                printf("两矩阵相乘无意义!\n");
                return;
            }
            for(int i=1;i<=row_b;i++)
            for(int j=1;j<=col_a;j++)
            {  int sum=0;
               for(int k=1;k<=col_a;k++)
               {
                 sum+=B[i][k]*A[k][j];
               }
               C[i][j]=sum;
            }
            printf("B*A=\n");
            for(int i=1;i<=row_b;i++)
            {
            for(int j=1;j<=col_a;j++)
             printf("%d ",C[i][j]);
             printf("\n");
            }

            break;
        }
        else
        {
            printf("输入非法！请重新输入\n");
            continue;
        }
    }
    
}
int main()
{

    while (1)
    {
        printf("请输入你的选择：\n");
        printf("1: 矩阵相加\n");
        printf("2.矩阵相减\n");
        printf("3.矩阵相乘\n");
        printf("4.矩阵转置\n");
        printf("5.退出！\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Add();
            break;
        case 2:
            Subtraction();
            break;
        case 3:
            Multiplication();
            break;
        case 4:
            TransposeTSMatrix();
            break;
        case 5:
            return 0;
        case 6:
            printf("输入非法！请重新输入!\n");
            break;
        }
    }
}