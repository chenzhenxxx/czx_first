#include<stdio.h>
#include<string.h>
int main()
{
    int n,cnt=0;
    scanf("%d",&n);
    getchar();
    char s[1000];
    char a[100][100];
    memset(a,' ',sizeof(a));
    gets(s);
    int len=strlen(s);
    int m=len;
    if(m%n==0)
     {
         m=m/n;
     }
     else
     {
         m=m/n+1;
     }
     for(int j=m-1;j>=0;j--)
      { 
      for(int i=0;i<n;i++)
        {if(cnt>=len)
        break;
        a[i][j]=s[cnt++];
        }
      }

      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
        printf("%c",a[i][j]);
        printf("\n");
      }


}