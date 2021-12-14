#include <stdio.h>
struct name{
    char dbm[20];
    char zjm[20];
    char xin[20];
};
struct fact
{
    char number[20];
    struct name wholename;
};
void print(struct fact *p);
main()
{
    struct fact fare[5];
    struct fact *p;
    p=&fare[0];
    for(int i=0;i<5;i++)
    {   printf("please input the number:\n");
        scanf("%s",fare[i].number);
        printf("please input the dbname:\n");
        scanf("%s",fare[i].wholename.dbm);
        printf("please input the zjname:\n");
        scanf("%s",fare[i].wholename.zjm);
        printf("please input the xin:\n");
        scanf("%s",fare[i].wholename.xin);
        
    }
    print(p);

}
void print(struct fact *p)
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("%s %s ",p[i].wholename.xin,p[i].wholename.dbm);
        if(p[i].wholename.zjm[0]!='1')
        {   printf("%c.",p[i].wholename.zjm[0]);
            
        }
         printf(" -- %s\n",p[i].number);
    }
}