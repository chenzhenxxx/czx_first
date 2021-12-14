#include <stdio.h>
#include <string.h>
 
int x[100]={0},y[100]={0},z[100]={0};
int main()
{
    char a[100],b[100];//定义两个字符数组来接收两个大数；
    int i,j,m,n,q;
    scanf("%s %s",a,b);
    m=strlen(a);
    n=strlen(b);
    j=0;
    for(i=m-1;i>=0;i--)//字符数组转化为倒序int型数组；
    {
        x[j]=a[i]-'0';
        j++;
    }
    j=0;
    for(i=n-1;i>=0;i--)
    {
        y[j]=b[i]-'0';
        j++;
    }
    if(m>n)//判断减数与被减数的位数
    {
        sub(x,y,m);
    }
    else if(m<n)
    {
        printf("-");
        sub(y,x,n);
    }
    else
    {
        for(i=m-1;i>=0;i--)
        {
            if(x[i]!=y[i])
            {
                if(x[i]>y[i])
                {
                    sub(x,y,m);
                    break;
                }
                else
                {
                    printf("-");
                    sub(y,x,m);
                    break;
                }
            }
            else
            {
                printf("0");
                printf("\n");
                break;
            }
        }
    }
    return 0;
}
void sub(int x[],int y[],int p)
{
    int i,o;
    for(i=0;i<p;i++)//进行相减
    {
        if(x[i]>=y[i])
        {
            z[i]=x[i]-y[i];
        }
        else
        {
            z[i]=x[i]-y[i]+10;
            x[i+1]--;
        }
    }
    for(i=p-1;i>=0;i--)//排除前几位为零的情况
    {
        if(z[i]!=0)
        {
            o=i;
            break;
        }
    }
    for(i=o;i>=0;i--)//倒序打出结果
    {
        printf("%d",z[i]);
    }
    printf("\n");
}