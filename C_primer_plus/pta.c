#include <stdio.h>
typedef struct stud
{
  char num[5];
  char name[20];
  int score;
}Stu;
main()
{ int n;
  int sum=0;
  double ave;
  scanf("%d",&n);
  Stu stu[n];
  int i;
  for(i=0;i<n;i++)
  {
    scanf("%s %s %d",stu[i].num,stu[i].name,&stu[i].score);
    sum+=stu[i].score;
  }
   ave=sum*1.0/n;
   printf("%.2f",ave);
   for(i=0;i<n;i++)
   {
     if(stu[i].score<ave)
     printf("%s %s %d\n",stu[i].num,stu[i].name,stu[i].score);
   }
}
