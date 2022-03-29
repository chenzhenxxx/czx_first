#include<stdio.h>
#include<stdlib.h>
int max_yin(int fz,int fm)
{
      int x;
    if(abs(fz)>fm)
    x=fm;
    else
    x=abs(fz);
    for( int i=x;i>=1;i--)
    {
        if(fz%i==0&&fm%i==0)
        return i;
    }
    return 1;
}
int main()
{
     long int t1,t2,zs=0,n,i;
    long int fz=0,fm=1;
    scanf("%ld",&n);
    for(i=0;i<n;i++)
     {
         scanf("%ld/%ld",&t1,&t2);
          fz=fz*t2+fm*t1;
          fm*=t2;
          int gy=1;

          if(fz!=0&&fm!=0)
          gy=max_yin(fz,fm);
         if(gy!=0)
         {
          fz/=gy;
          fm/=gy;
         }
     }

       if(abs(fz)>=fm&&(fz!=0&&fm!=0))
        {
           zs=fz/fm;
           fz=fz%fm;
        }

        if(zs!=0)
         {
            printf("%d",zs);
         }
         if(zs!=0&&fz!=0&&fm!=0)
          printf(" ");

          if(fz!=0&&fm!=0)
           printf("%d/%d",fz,fm);

           if(fz==0&&zs==0)
            printf("0");

}