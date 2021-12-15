#include <stdio.h>
#include<time.h>
void random (int*p,int size,int n)
{    int a;
     srand((int)time(0));
     int *b=(int *)malloc(n*sizeof(int));
     while(n)
     { a=rand()%size;
       if(b[a]==0)
       {
           printf("%d\n",p[a]);
           b[a]++;
           n--;
       }
       
       
     }
}
int main()
{
    int a[50],size,n;
    scanf("%d %d",&size,&n);
    for(int i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    random(a,size,n);
    return 0;

}