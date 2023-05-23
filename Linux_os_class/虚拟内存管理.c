#include<stdio.h>
#define PN 7//页面数
#define PAGESIZE 1024//页面大小：1K
 
typedef struct 
{
    int P;//存在标志
    int M;//修改标志
    int pno;//页号
    int bno;//物理块号
    int place;//位移
}PAGETAB;
 
void change(PAGETAB s[]){
    int flag=1;
    int a,p;//a为逻辑地址，p为页号
    int x=0,i=0;
    int weiyi,place;//位移量，物理地址
    int found=0;
    char st;//缺页状态
    while(flag==1){
        st='N';
        printf("请输入逻辑地址：");
        scanf("%d",&a);
        p=a/PAGESIZE;
        weiyi=a%PAGESIZE;
        if(p>=PN){
            printf("逻辑地址非法！\n");
        }
        else{
            for(i=0;i<PN;i++){
                if(s[i].pno==p){//利用页号p找到对应页
                    break;
                }
            }
            if(s[i].P==0){//状态为0
                st='Y';//说明缺页
                for(x;x<PN;x++){//s页
                    if(s[x].P==1){
                       found=1;
                       break; 
                    }
                }//说明在s页中有状态为1的表，跳过下面的if
                if(found=0){//说明s页中没有状态为1的表，执行此if
                    for(x=0;x<PN;x++){
                        if(s[x].P==1){
                            break;
                        }
                    }
                }
                found=0;
                s[x].P=0;//s页状态修改为0
                s[i].bno=s[x].bno;//p页物理块号记为s页所在的物理块号
                s[x].bno=0;//s页块号修改为0
                s[i].P=1;//p页状态修改为1
            }   
            place=s[i].bno*PAGESIZE+weiyi;//物理地址=物理块号*页面大小+页内位移
            printf("逻辑地址：%d\n页号：%d\n页内位移：%d\n是否缺页：%c\n物理块：%d\n物理地址：%d\n",a,p,weiyi,st,s[i].bno,place);
        }
        printf("是否继续？(1:是 0:否):");
        scanf("%d",&flag);
    }
}
 
void show(PAGETAB s[]){
    int i;
    for(i=0;i<PN;i++){
        printf("页号：%d\n状态：%d\n物理块号：%d\n",s[i].pno,s[i].P,s[i].bno);
    }
}
 
void main(){
    PAGETAB s[PN];
    int i,sel;
    int flag=1;
    for(i=0;i<PN;i++){
        s[i].pno=i;
        if(i<3){
            s[i].P=1;
        }
        else{
            s[i].bno=0;
            s[i].P=0;
        }
    }
    s[0].bno=9;
    s[1].bno=5;
    s[2].bno=4;
 
    while(flag==1){
        printf("************系统菜单************\n");
        printf("***********1: change***********\n");
        printf("***********2: show  ***********\n");
        printf("***********0: exit  ***********\n");
        printf("*******************************\n");
        printf("输入你的选择(0-2)：");
        scanf("%d",&sel);
 
        switch (sel)
        {
        case 1:change(s);break;
        case 2:show(s);break;
        case 0:flag=0;break;
        
        default:printf("输入错误！");break;
        }
    }
}