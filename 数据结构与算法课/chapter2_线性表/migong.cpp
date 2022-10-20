
 
#include <stdio.h>
#define M 4 //行数
#define N 4 //列数
#define MAX_SIZE 100 //栈最多元素个数
// mg为迷宫二维数组:一个迷宫,其四周加上均为1的边框
int mg[M + 2][N + 2] = {
    {1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1},
    {1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1}
};
/*---------------------定义全局变量-----------------------*/
// 定义栈和存放最短路径的数组
struct
{
    int i; // 横坐标
    int j; // 纵坐标
    int di;
}St[MAX_SIZE], Path[MAX_SIZE];
int top = -1; //栈顶指针
int cnt = 1; //路径数计数
int minlen = MAX_SIZE; //最短路径长度
/*--------------------------------------------------------*/
/**
*   功能:
*       输出一条路径并求最短路径
*
*/
static void disp_path()
{
    int k;
    printf("  %5d: ", cnt++); // 输出第cnt条路径
    for(k = 0; k <= top; k++)
        printf("(%d,%d)", St[k].i, St[k].j);
    printf("\n");
    if(top + 1 < minlen) //比较找最短路径
    {
        for(k = 0; k <= top; k++) //将最短路径存放在path中
            Path[k] = St[k];
        minlen = top + 1; // 将最短路径长度存放在minlen中
    }
}
/**
*   功能:
*       输出第一条最短路径
*
*/
static void disp_min_path()
{
    int k;
    printf("最短路径如下:\n");
    printf("长度: %d\n", minlen);
    printf("路径: ");
    for(k = 0; k < minlen; k++)
        printf("(%d,%d)", Path[k].i, Path[k].j);
    printf("\n");
}
/**
*   功能:
*       求迷宫路径
*   @xi:入口横坐标
*   @yi:入口纵坐标
*   @xe:出口横坐标
*   @ye:出口纵坐标
*/
static void mg_path(int xi, int yi, int xe, int ye)
{
    int i, j, i1, j1, di;
    bool is_find;
    top++; // 进栈
    St[top].i = xi;
    St[top].j = yi;
    St[top].di = -1; mg[xi][yi] = -1; // 初始方块进栈
    while(top > -1) // 栈不空时循环
    {
        i = St[top].i; j = St[top].j; // 取栈顶方块(i,j)
        di = St[top].di;
        if(i == xe && j == ye) // 找到了出口
        {
            disp_path(); // 输出一条路径
            mg[i][j] = 0; // 让出口变为其他路径可走方块
            top--; // 出口退栈,即回退一个方块
            i = St[top].i; j = St[top].j;
            di = St[top].di; // 让栈顶方块变为当前方块
        }
        is_find = false; // 找下一个可走方块(i1,j1);
        while(di < 4 && !is_find)
        {
            di++;
            switch(di)
        

            {
            case 0:
                i1 = i - 1;
                j1 = j;
                break;
            case 1:
                i1 = i;
                j1 = j + 1;
                break;
            case 2:
                i1 = i + 1;
                j1 = j;
                break;
            case 3:
                i1 = i;
                j1 = j - 1;
                break;
            }
            if(mg[i1][j1] == 0)
                is_find = true;
        }
        if(is_find) // 找到了下一个可走方块(i1,j1)
        {
            St[top].di = di; // 修改原栈顶元素的di值
            top++; St[top].i = i1, St[top].j = j1;
            St[top].di = -1; // 下一个可走方块(i1,j1)进栈
            mg[i1][j1] = -1; // 避免重复走到该方块
        }
        else // 没有路径可走,则(i,j)方块退栈
        {
            mg[i][j] = 0; // 让该位置变为其他路径可走方块
            top--;
        }
    }
    disp_min_path(); // 输出最短路径
}

int main()
{
    printf("迷宫所有路径如下:\n");
    mg_path(1, 1, M, N);

    return 0;
}
