#define CSIZE 4
#include <stdio.h>
struct name 
{
    char ming[20];
    char xin[20];
};
struct student
{
    struct name Name;
    float grade[3];
    float ave;
};

void print(struct student*p);
void ave (struct student *p);
void print_ave(struct student*p);
main()
{   struct student stu[CSIZE];
    struct student *p;
    float sum=0;
    for(int i=0;i<4;i++)
    {
        printf("please input your name:\n");
        scanf("%s %s",stu[i].Name.xin,stu[i].Name.ming);
        printf("please input your grade\n");
        scanf("%f %f %f",&stu[i].grade[0],&stu[i].grade[1],&stu[i].grade[2]);
        
     }
     p=&stu[0];
     ave(p);
    print(p);
    print_ave(p);

}
void print(struct student *stu)
{
    for(int i=0;i<4;i++)
    printf("%s%s grade1:%f grade2:%f grade3:%f  ave=%f\n",stu[i].Name.xin,stu[i].Name.ming,stu[i].grade[0],stu[i].grade[1],stu[i].grade[2],stu[i].ave);


}
void print_ave(struct student *p)
{   double sum;
    for(int i=0;i<4;i++)
    sum+=p[i].ave;
    printf("the whole average :%lf\n",sum*1.0/4);   
}
void ave(struct student *p)
{  
  for(int i=0;i<4;i++)
  {  float sum=0;
     sum+=p[i].grade[0]+p[i].grade[1]+p[i].grade[2];
     p[i].ave=sum*1.0/3;
      
  }
}
