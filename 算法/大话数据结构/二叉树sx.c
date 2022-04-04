#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */
#define MAX_TREE_SIZE 100
typedef int Status;
typedef int TElemType;
typedef TElemType SqBiTree[MAX_TREE_SIZE];
typedef struct 
{
    int level;//节点所在的层
    int order;//本层的序号
}Position;
TElemType Nil=0;
#define ClearBiTree InitBiTree
Status visit(TElemType c)
{
    printf("%d ",c);
    return OK;
}
Status InitBiTree(SqBiTree T)
{
    for(int i=0;i<MAX_TREE_SIZE;i++)
     {
         T[i]=Nil;
     }
}
Status CreateBiTree(SqBiTree T)
{   int i=0;
    while(i<10)
     {
         T[i]=i+1;
         if(i!=0&&T[(i+1)/2-1]==Nil&&T[i]!=Nil)
         {
             printf("the parent is empty.\n");
             exit(ERROR);
         }
         i++;
     }
     while(i<MAX_TREE_SIZE)
      {
          T[i]=Nil;
          i++;
      }
}
Status BiTreeEmpty(SqBiTree T)
{
    if(T[0]==Nil)
     return 1;
     else 
     return 0;
}
int BiTreeDepth(SqBiTree T)
{    int i,j=0;
    for(i=MAXSIZE-1;i>=0;i--)
    if(T[i]!=Nil)
    break;
    do
    {
        j++;
    } while (pow(2,j)<i);
    return j;
    
}
Status Root(SqBiTree T,TElemType *e)
{
    if(BiTreeEmpty(T))
    return FALSE;
    else
    {
        *e=T[0];
        return e;
    }

}
TElemType Value(SqBiTree T,Position e)
{
    return T[(int)pow(2,e.level-1)+e.order-2];
}
Status Assign(SqBiTree T,Position e,TElemType value)
{
    int i=(int)pow(2,e.level-1)+e.order-2;
    if(value!=Nil&&T[(i+1)/2-1]==Nil)
    exit(ERROR);
    else if(value==Nil&&T[2*+1]!=Nil&&T[2*i+2]!=Nil)
    exit(ERROR);

    T[i]=value;
    return 1;
}
TElemType Parent(SqBiTree T,TElemType e)
{
    int i;
    for(i=MAX_TREE_SIZE-1;i>0;i--)
     {
         if(T[i]==e)
          return T[(i+1)/2-1];
     }
     return Nil;
}
TElemType LeftChild(SqBiTree T,TElemType e)
{
    int i;
    for(i=MAX_TREE_SIZE-1;i>0;i--)
     {
         if(T[i]==e)
          return T[2*i+1];
     }
     return Nil;
}
TElemType RightChild(SqBiTree T,TElemType e)
{
    int i;
    for(i=MAX_TREE_SIZE-1;i>0;i--)
     {
         if(T[i]==e)
          return T[2*i+2];
     }
     return Nil;
}
TElemType LeftSibling(SqBiTree T,TElemType e)
{
    int i;
    for(i=MAX_TREE_SIZE-1;i>0;i--)
     {
         if(T[i]==e&&i%2==0)
          return T[i-1];
     }
     return Nil;
}
TElemType RightSibling(SqBiTree T,TElemType e)
{
    int i;
    for(i=MAX_TREE_SIZE-1;i>0;i--)
     {
         if(T[i]==e&&i%2)
          return T[i+1];
     }
     return Nil;
}
void PreTraverse(SqBiTree T,int e)
{
     visit(T[e]);
     if(T[2*e+1]!=Nil)
     PreTraverse(T,2*e+1);
     if(T[2*e+2]!=Nil)
     PreTraverse(T,2*e+2);

}
Status PreOrderTraverse(SqBiTree T)
{
      if(!BiTreeEmpty(T))
       PreTraverse(T,0);
       printf("\n");
       return 1;
}
void InTraverse(SqBiTree T,int e)
{
   
     if(T[2*e+1]!=Nil)
     PreTraverse(T,2*e+1);
      visit(T[e]);
     if(T[2*e+2]!=Nil)
     PreTraverse(T,2*e+2);
}
Status InOrderTraverse(SqBiTree T)
{
    if(!BiTreeEmpty(T))
       InTraverse(T,0);
       printf("\n");
       return 1;
}
void PostTraverse(SqBiTree T,int e)
{
    if(T[2*e+1]!=Nil)
     PreTraverse(T,2*e+1);
     
     if(T[2*e+2]!=Nil)
     PreTraverse(T,2*e+2);
      visit(T[e]);
}
Status PostOrderTraverse(SqBiTree T)
{
    if(!BiTreeEmpty(T))
       PostTraverse(T,0);
       printf("\n");
       return 1;
}
void LevelOrderTraverse(SqBiTree T)
{
    int i,j;
    for(i=0;i<MAX_TREE_SIZE;i++)
     {
         if(T[i]==Nil)
          break;
     }
      
      for(j=0;j<i;j++)
      {   if(T[j]!=Nil)
          visit(T[j]);
      }
      printf("\n");
}
void Print(SqBiTree T)
{
    int j,k;
	Position p;
	TElemType e;
    for(int i=1;i<=BiTreeDepth(T);i++)
    {
        printf("第%d层:\n",i);
        for(k=1;k<=pow(2,j-1);k++)
         {
             p.level=i;
             p.order=k;
             e=Value(T,p);
             if(e!=Nil)
             printf("%d: %d",k,e);

         }
         printf("\n");
    }
}
main()
{
	Status i;
	Position p;
	TElemType e;
	SqBiTree T;
	InitBiTree(T);
	CreateBiTree(T);
	printf("建立二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T,&e);
	if(i)
		printf("二叉树的根为：%d\n",e);
	else
		printf("树空，无根\n");
	printf("层序遍历二叉树:\n");
	LevelOrderTraverse(T);
	printf("前序遍历二叉树:\n");
	PreOrderTraverse(T);
	printf("中序遍历二叉树:\n");
	InOrderTraverse(T);
	printf("后序遍历二叉树:\n");
	PostOrderTraverse(T);
	printf("修改结点的层号3本层序号2。");
	p.level=3;
	p.order=2;
	e=Value(T,p);
	printf("待修改结点的原值为%d请输入新值:50 ",e);
	e=50;
	Assign(T,p,e);
	printf("前序遍历二叉树:\n");
	PreOrderTraverse(T);
	printf("结点%d的双亲为%d,左右孩子分别为",e,Parent(T,e));
	printf("%d,%d,左右兄弟分别为",LeftChild(T,e),RightChild(T,e));
	printf("%d,%d\n",LeftSibling(T,e),RightSibling(T,e));
	ClearBiTree(T);
	printf("清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T,&e);
	if(i)
		printf("二叉树的根为：%d\n",e);
	else
		printf("树空，无根\n");
	
	return 0;
}