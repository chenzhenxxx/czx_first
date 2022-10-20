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

void Print(TSMarix C)
{
    int t = 1;
    for (int i = 1; i <= C.row; i++)
    {
        for (int j = 1; j <= C.col; j++)
        {
            if (t > C.nums)
            {
                printf("0 ");
                continue;
            }
            if (C.data[t].row == i && C.data[t].col == j)
            {
                printf("%5d", C.data[t].value);
                t++;
            }
            else
            {
                printf("%5d",0);
            }
        }
        printf("\n");
    }
}
void Create(TSMarix *A)
{
    A->nums = 1;
    int tmp = 0;
    printf("请输入数组行数：");
    scanf("%d", &A->row);
    printf("请输入数组列数：");
    scanf("%d", &A->col);
    printf("请输入数据：！\n");
    for (int i = 1; i <= A->row; i++)
        for (int j = 1; j <= A->col; j++)
        {
            scanf("%d", &tmp);
            if (tmp != 0)
            {
                A->data[A->nums].value = tmp;
                A->data[A->nums].row = i;
                A->data[A->nums].col = j;
                A->nums++;
            }
        }
}
void TransposeTSMatrix(TSMarix A)
{
    int tmp = 0;
    TSMarix B;

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
    Print(B);
}
void Add(TSMarix A, TSMarix B)
{

    int tmp = 0;
    TSMarix C;
    C.nums = 1;
    if (A.row != B.row || A.col != B.row)
    {
        printf("两矩阵行列不一致，无法运算!\n");
        return;
    }
    C.col = A.col;
    C.row = A.row;
    int i = 1, j = 1;
    for (i, j; i < A.nums && j < B.nums;)
    {
        if (A.data[i].row == B.data[j].row)
        {
            if (A.data[i].col == B.data[j].col)
            {
                C.data[C.nums].col = A.data[i].col;
                C.data[C.nums].row = A.data[i].row;
                C.data[C.nums].value = A.data[i].value + B.data[j].value;
                C.nums++;
                i++;
                j++;
            }
            else if (A.data[i].col > B.data[j].col)
            {
                C.data[C.nums].col = B.data[j].col;
                C.data[C.nums].row = B.data[j].row;
                C.data[C.nums].value = B.data[j].value;
                C.nums++;
                j++;
            }
            else
            {
                C.data[C.nums].col = A.data[i].col;
                C.data[C.nums].row = A.data[i].row;
                C.data[C.nums].value = A.data[i].value;
                C.nums++;
                i++;
            }
        }
        else if (A.data[i].row > B.data[j].row)
        {
            C.data[C.nums].col = B.data[j].col;
            C.data[C.nums].row = B.data[j].row;
            C.data[C.nums].value = B.data[j].value;
            C.nums++;

            j++;
        }
        else
        {
            C.data[C.nums].col = A.data[i].col;
            C.data[C.nums].row = A.data[i].row;
            C.data[C.nums].value = A.data[i].value;
            C.nums++;
            i++;
        }
    }
    if (i < A.nums)
    {
        while (i < A.nums)
        {
            C.data[C.nums].col = A.data[i].col;
            C.data[C.nums].row = A.data[i].row;
            C.data[C.nums].value = A.data[i].value;
            C.nums++;
            i++;
        }
    }
    if (j < B.nums)
    {
        while (j < B.nums)
        {
            C.data[C.nums].col = B.data[j].col;
            C.data[C.nums].row = B.data[j].row;
            C.data[C.nums].value = B.data[j].value;
            C.nums++;
            j++;
        }
    }
    Print(C);
}
void Subtraction(TSMarix A, TSMarix B)
{
    int choice;
    while (1)
    {
        printf("1.A-B\n");
        printf("2.B-A\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            for (int i = 1; i < B.nums; i++)
            {
                B.data[i].value = -B.data[i].value;
            }
            printf("A-B=\n");
            Add(A, B);
            break;
        }
        else if (choice == 2)
        {
            for (int i = 1; i < A.nums; i++)
            {
                A.data[i].value = -A.data[i].value;
            }
            printf("B-A=\n");
            Add(A, B);
            break;
        }
        else
        {
            printf("输入非法!,请重新输入\n");
        }
    }
}
int get_value(TSMarix A, int i, int j)
{
    int tmp = 0;
    for (int k = 1; k < A.nums; k++)
    {
        if (A.data[k].row == i && A.data[k].col == j)
        {
            tmp = A.data[k].value;
            break;
        }
    }
    return tmp;
}
void Multiplication(TSMarix A, TSMarix B)
{
    int choice;
    TSMarix C;
    C.nums = 1;
    while (1)
    {
        printf("1.A*B\n");
        printf("2.B*A\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            if (A.col != B.row)
            {
                printf("两矩阵行列不同，无法相乘!\n");
                return ;
            }
            C.col=B.col;
            C.row=A.row;
            for (int i = 1; i <= A.row; i++)
            {
                for (int j = 1; j <= B.col; j++)
                {
                    int sum = 0;
                    for (int k = 1; k <= A.col; k++)
                    {
                        sum += get_value(A, i, k) * get_value(B, k, j);
                    }
                    if (sum != 0)
                    {
                        C.data[C.nums].value = sum;
                        C.data[C.nums].col = j;
                        C.data[C.nums].row = i;
                        C.nums++;
                    }
                }
            }
            printf("A*B\n");
            Print(C);
            break;
        }
        else if(choice==2)
        {
             if (B.col != A.row)
            {
                printf("两矩阵行列不同，无法相乘!\n");
                return ;
            }
            C.col=A.col;
            C.row=B.row;
            for (int i = 1; i <= B.row; i++)
            {
                for (int j = 1; j <= A.col; j++)
                {
                    int sum = 0;
                    for (int k = 1; k <= B.col; k++)
                    {
                        sum += get_value(B, i, k) * get_value(A, k, j);
                    }
                    if (sum != 0)
                    {
                        C.data[C.nums].value = sum;
                        C.data[C.nums].col = j;
                        C.data[C.nums].row = i;
                        C.nums++;
                    }
                }
            }
            printf("B*A=\n");
            Print(C);
            break;
        }
        else
        {
            printf("输入非法!请重新输入\n");


        }
    }
}
int main()
{

    while (1)
    {
         printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("           三元组矩阵的加、减、乘         \n");
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("           1、矩阵的加法                           \n");
        printf("           2、矩阵的减法                           \n");
        printf("           3、矩阵的乘法                           \n");
        printf("           4、矩阵转置                             \n");
        printf("           5   退出                                \n");
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("请输入你的选择：\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            TSMarix A;
            printf("请输入A矩阵信息\n");
            Create(&A);
            TSMarix B;
            printf("请输入B矩阵信息\n");
            Create(&B);
            printf("A+B=\n");
            Add(A, B);
            break;
        case 2:
            TSMarix C;
            printf("请输入C矩阵信息\n");
            Create(&C);
            TSMarix D;
            printf("请输入D矩阵信息\n");
            Create(&D);
            Subtraction(C, D);
            break;
        case 3:
            TSMarix E;
            printf("请输入E矩阵信息\n");
            Create(&E);
            TSMarix F;
            printf("请输入F矩阵信息\n");
            Create(&F);
            Multiplication(E, F);

            break;
        case 4:
            TSMarix G;
            printf("请输入G矩阵信息\n");
            Create(&G);
            TransposeTSMatrix(G);
            break;
        case 5:
            return 0;
        default:
            printf("输入非法！请重新输入!\n");
            break;
        }
    }
}