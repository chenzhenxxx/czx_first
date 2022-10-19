#include<stido.h>
void Find_location(int*start,int size, int n,int up[],int down[],int j[])
//start 开始位置  size每个元素占存储单元大小 n 维数 up[]存上限 down[]存下限
{
    int p,q;
    for(int q=1;q<=n;q++)
    {
        int temp=1;
        for(p=q+1;p<=n;p++)
        {
            temp*=(up[p]-down[p]+1);
        }
        start+=size*temp*(j[q]-down[q]);

    }
    return start;
}
int main()
{

}