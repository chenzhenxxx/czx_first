#include <stdio.h>
#include <stdlib.h>
struct student 
{
  char name[10];
  int grade;
};
main()
{   struct student stu[10],out[10];
   FILE*fp;
   int n;
   printf("the people you want to add:\n");
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
     printf("the name:\n");
     scanf("%s",stu[i].name);
     printf("the grade:\n");
     scanf("%d",&stu[i].grade);
   }
   if((fp=fopen("student.txt","w"))==NULL)
   {
     fprintf(stderr,"can't open the file");
     exit(EXIT_FAILURE);
   }
   for(int i=0;i<n;i++)
   fprintf(fp,"%s %d",stu[i].name,stu[i].grade);
   fclose(fp);
   if((fp=fopen("student.txt","r"))==NULL)
   {
     fprintf(stderr,"can't read this file:\n");
     exit(EXIT_FAILURE);
   }
   for(int i=0;i<n;i++)
   {
     fscanf(fp,"%s %d",out[i].name,&out[i].grade);
     printf("%s %d",out[i].name,out[i].grade);
   }

}