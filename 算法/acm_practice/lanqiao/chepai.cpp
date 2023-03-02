#include<bits/stdc++.h>
using namespace std;
int flag[7];
int judge()
{
    if((flag[1]==flag[2])&&(flag[2]==flag[3])||(flag[2]==flag[3])&&(flag[3]==flag[4])||(flag[3]==flag[4])&&(flag[4]==flag[5])||(flag[4]==flag[5])&&(flag[5]==flag[6]))
    {
        return 1;
    }
    return 0;
}
int main()
{
    
    long long cnt=0;
   for(int i=0;i<=15;i++)
     {   memset(flag,0,sizeof(flag));
        flag[1]=i;
        for(int j=0;j<=15;j++)
         {   
            flag[2]=j;
            for(int k=0;k<=15;k++)
            {    flag[3]=k;
                for(int m=0;m<=9;m++)
                {    flag[4]=m;
                    for(int n=0;n<=9;n++)
                     {   flag[5]=n;
                        for(int v=0;v<=9;v++)
                        {   flag[6]=v;
                            if(!judge())
                            {
                                cnt++;
                            }
                        }
                     }
                }
            }
         }
    }
    cout<<cnt;
}