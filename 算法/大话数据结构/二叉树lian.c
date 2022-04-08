#include "string.h"
#include <stdio.h>    
#include <stdlib.h>   
#include "math.h"  
#include "time.h"
int overflow=0;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;
int treeIndex=1;
typedef char String[24];
String str;
Status StrAssign(String T,char *chars)
{
   int i;
	if(strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{
		T[0]=strlen(chars);
		for(i=1;i<=T[0];i++)
			T[i]=*(chars+i-1);
		return OK;
	}
}
typedef char TElemType;
TElemType Nil=' ';
Status visit(TElemType e)
{
	printf("%c ",e);
	return OK;
}
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
Status InitBiTree(BiTree *T)
{
	*T=NULL;
	return OK;
}
void DestroyBiTree(BiTree *T)
{
	if(*T)
	{
		if((*T)->lchild)
		 {
			 DestroyBiTree(&(*T)->lchild);
		 }
		 if((*T)->rchild)
		 {
			 DestroyBiTree(&(*T)->rchild);
		 }
		 free(*T);
		 *T=NULL;
	}
}
void CreateBiTree(BiTree *T)
{
	TElemType ch;
	ch=str[treeIndex++];
	if(ch=='#')
	 *T=NULL;
	 else
	  {
		  *T=(BiTree)malloc(sizeof(BiTNode));
		   (*T)->data=ch;
		   CreateBiTree(&(*T)->lchild);
		   CreateBiTree(&(*T)->rchild);
	  }
}
Status BiTreeEmpty(BiTree T)
{
	if(T)
	return 0;
	else
	return 1;
}
#define ClearBiTree DestroyBiTree
int BiTreeDepth(BiTree T)
{
      int i,j;
	  if(!T)
	   {
		   return 0;
	   }
	   if(T->lchild)
	    i=BiTreeDepth(T->lchild);
		else
		i=0;
		if(T->rchild)
		 j=BiTreeDepth(T->rchild);
		 else 
		 j=0;
		 return i>j?i+1:j+1;
}
TElemType Root(BiTree T)
{
   if(!T)
   return 0;
   else
   return T->data;
}
TElemType Value(BiTree p)
{
	return p->data;
}
void Assign(BiTree p,TElemType value)
{
	p->data=value;
}
void PreOrderTraverse(BiTree T)
{   if(!T)
    return;
	visit(T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}
void InOrderTraverse(BiTree T)
{   if(!T)
    return;
	
	PreOrderTraverse(T->lchild);
	visit(T->data);
	PreOrderTraverse(T->rchild);
}
void PostOrderTraverse(BiTree T)
{
	if(!T)
    return;
	
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
	visit(T->data);
}
int main()
{
	int i;
	BiTree T;
	TElemType e1;
	InitBiTree(&T);

	
	StrAssign(str,"ABDH#K###E##CFI###G#J##");

	CreateBiTree(&T);

	printf("构造空二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	e1=Root(T);
	printf("二叉树的根为: %c\n",e1);

	printf("\n前序遍历二叉树:");
	PreOrderTraverse(T);
	printf("\n中序遍历二叉树:");
	InOrderTraverse(T);
	printf("\n后序遍历二叉树:");
	PostOrderTraverse(T);
	ClearBiTree(&T);
	printf("\n清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T);
	if(!i)
		printf("树空，无根\n");
	
	return 0;
}