#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char a[5000][10];
char *b[3000];
struct 
{
    char name[10];
    double grade;
}stu[6000];
bool cmp(char *a,char *b)
{
    if(strcmp(a,b)<0)
    return 1;
    else return 0;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
     {
         scanf("%s",&a[i]);
     }
     int k,sum=0,cnt=0;
     cin>>k;
     for(int i=0;i<k;i++)
      {
          scanf("%s %lf",stu[i].name,&stu[i].grade);
          sum+=stu[i].grade;
      }
      double ave;
      ave=sum*1.0/k;
      for(int i=0;i<k;i++)
       {   int flag=0;
           if(stu[i].grade>=ave)
            {
                for(int j=0;j<n;j++)
                 {
                     if(strcmp(a[j],stu[i].name)==0)
                     {
                         flag=1;
                         break;
                     }
                 }
                 if(flag==0)
                 b[cnt++]=stu[i].name;
            }
       }
       if(cnt==0)
        {
            printf("Bing Mei You\n");
        }
        else 
        {
       sort(b,b+cnt,cmp);
       for(int i=0;i<cnt;i++)
       printf("%s\n",b[i]);
        }


}