#include<iostream>
#include<cstring>
using namespace std;
int main()
{   int flag1=0,flag2=0;
    char a[100000];
    cin>>a;
     char b[100000];
     strcpy(b,a);
     
    int n=strlen(a);
    for(int i=0;i<n-1;i++)
    {
      if(a[i]=='A'&&a[i+1]=='B')
        {
            flag1=1;
            a[i]=1;
            a[i+1]=1;
            break;
        }
    }
         for(int i=0;i<n;i++)
         {
        if(a[i]=='B'&&a[i+1]=='A')
        {
            flag2=1;
            a[i]=1;
            a[i+1]=1;
            
        }
        if(flag1&&flag2)
          {
              printf("YES\n");
             return 0;
          }
         }
        
       
       flag1=0,flag2=0;
      for(int i=0;i<n-1;i++)
    {
      if(b[i]=='B'&&b[i+1]=='A')
        {
            flag1=1;
            b[i]=1;
            b[i+1]=1;
            break;
        }
    }
         for(int i=0;i<n;i++)
         {
        if(b[i]=='A'&&b[i+1]=='B')
        {
            flag2=1;
            b[i]=1;
            b[i+1]=1;
           
        }
        if(flag1&&flag2)
          {
              printf("YES\n");
             return 0;
          }
         }
    printf("NO\n");

}