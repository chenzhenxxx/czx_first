#include<stdio.h>
int f[1010];
char name[50000][7];
int find (int x)
{
    if(f[x]!=x)
    f[x]=find(f[x]);
    return f[x];

}
int main()
{   int cnt=0;
    char tmp[10];
    char ch;
    scanf("%c",&ch);
    for(int i=0;i<1010;i++)
       f[i]=i;
    while(ch!='$')
    {   
        int j,t,fa;
        scanf("%s",&tmp);
        while( getchar()!= '\n');

        for( j=0;j<cnt;j++)
        {
            if(strcmp(name[j],tmp)==0)
               break;
        }
        if(j!=cnt)
        {
        t=j;
        }
        else
        {
            strcpy(name[cnt++],tmp);
            t=cnt-1;
        }

        if(ch=='#')
         fa=t;
         else if(ch=='+')
          {
               f[find(t)]=find(fa);
          }
         else
         {
             printf("%s %s\n",name[t],name[find(t)]);
         }
        scanf("%c",&ch);
    }
}