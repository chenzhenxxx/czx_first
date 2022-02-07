int sushu[10000];//存素数
int book[10000];//标记是否为素数 ，1不是素数。
int count;//个数
void ejudge(int n)
{
    int i,j;
     for(i=2;i*i<=n;i++)  //为啥是i*i下文会讲
     {
          if(book[i]==0)
           {
               sushu[count++]=i;
           }
            
            for(j=0;j*i<=n;j++)
             {
                book[i*j]=1;//素数的倍数不是素数。
             }
     }
      for(;i<=n;i++)  //sqrt(n)以后的数。
      if(book[i]==0)
       {
        sushu[count++]=i;
       }
      
}