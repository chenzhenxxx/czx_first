#include<stdio.h>
main()
{
    char ml[20];
    char name[20];
    int num,count=0;
    char Name[1000][20];
    int number[1000];
    int a[1000];
    int k=0;

    scanf("%s",&ml);
    while(strcmp(ml,"end")!=0)
     {   scanf("%s %d",&name,&num);
         if(strcmp(ml,"insert")==0)
          {
              strcpy(Name[count],name);
              number[count]=num;
              count++;
          }
          else if(strcmp(ml,"find")==0)
           {     int flag=0;
               for(int i=0;i<count;i++)
                {
                    if(strcmp(Name[i],name)==0)
                    {   flag=1;
                        a[k]=number[i];
                        k++;
                        break;
                    }
                }

                if(flag==0)
               {

                a[k]=-1;
                k++;
               }
           }
            scanf("%s",&ml);
     }
     for(int j=0;j<k;j++)
     {
         printf("%d\n",a[j]);
     }
}