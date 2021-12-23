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
     exit(EXIT_FAILURE);
   }
   for(int i=0;i<n;i++)
  
    {
      fprintf(fp,"%s %d",stu[i].name,stu[i].grade);
      printf("the point now is %d\n",ftell(fp));
    }
   fclose(fp);
   if((fp=fopen("student.txt","r"))==NULL)
   {
     fprintf(stderr,"can't read this file:\n");
     exit(EXIT_FAILURE);
   }  
   fscanf(fp,"%s %d",out[0].name,&out[0].grade);
   printf("%s %d",out[0].name,out[0].grade);
   fseek(fp,7,SEEK_CUR);
   fscanf(fp,"%s %d",out[1].name,&out[1].grade);
   printf(" %s %d",out[1].name,out[1].grade);
   

}