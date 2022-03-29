#include <stdio.h>
int s[5001][5001];
int len;
void jia(int k)
{   for(int i=1;i<=len;i++)
    {
        s[k][i]=s[k-1][i]+s[k-2][i];
    }
     for(int j=1;j<=len;j++)
        if(s[k][j]>=10)
        {   s[k][j+1]+=s[k][j]/10;
        
            s[k][j]%=10;
            if(s[k][len+1]>0)len++;
        }
    
   
            
    
}
main()
{
    int n;
    len=1;
    scanf("%d",&n);
    s[1][1]=1;
    s[2][1]=2;
    for(int i=3;i<=n;i++)
    jia(i);
    for(int j=len;j>=1;j--)
    printf("%d",s[n][j]);

}