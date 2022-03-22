int sushu[10000];//存素数
int book[10000];//标记是否为素数 ，1不是素数。
int count;//个数
void xjudge(int n)
{
    int i,j;
     for(i=2;i<=n;i++)
     {
         if(book[i]==0)
         sushu[count++]=i;
         for(j=0;j<count&&i*sushu[j]<=n;j++)
         {
             book[i*sushu[j]]=1;
             if(i%sushu[j]==0)
             break;
         }
     }