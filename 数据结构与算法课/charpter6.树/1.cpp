#include<bits/stdc++.h>
#include<stack>
using namespace std;
#define DataType char
typedef struct Node
{
    DataType data;
    struct Node * Lchild;
    struct Node * Rchild;
}BiTNode,*BiTree;
void CreateBiTree(BiTree *root)//拓展先序创建二叉树
{
    char ch;
    ch=getchar();
    if (ch=='^')
    *root=NULL;
    else
    {
        *root=(BiTree)malloc(sizeof(BiTNode));
        (*root)->data=ch;
        CreateBiTree(&((*root)->Lchild));
        CreateBiTree(&((*root)->Rchild));
         
    }
}
void PostOrder(BiTree root)   //递归后序遍历
{
    if(root)
    {
        PostOrder(root->Lchild);
        PostOrder(root->Rchild);
        printf("%c",root->data);
    }

}
void InOrder(BiTree root)   //递归中序遍历
{
    if(root)
    {
        InOrder(root->Lchild);
        printf("%c",root->data);
        InOrder(root->Rchild);
        
    }

}
void PreOrder(BiTree root)   //递归先序遍历
{
    if(root)
    {   printf("%c",root->data);
        PreOrder(root->Lchild);
        PreOrder(root->Rchild);
        
    }

}
void feidigui_PreOrder(BiTree root)
{
    stack<BiTree> s;
    BiTree p;
    p=root;
    while(p!=NULL||!s.empty())
     {
        while(p!=NULL)
        {
            printf("%c",p->data);
            s.push(p);
            p=p->Lchild;
        }
        if(!s.empty())
        {   p=s.top();
            s.pop();
            p=p->Rchild;
        }
     }
}

void feidigui_InOrder(BiTree root)
{
    stack<BiTree> s;
    BiTree p;
    p=root;
    while(p!=NULL||!s.empty())
     {
        while(p!=NULL)
        {
            s.push(p);
            p=p->Lchild;
        }
        if(!s.empty())
        {   
           
            p=s.top();
            printf("%c",p->data);
            s.pop();
            p=p->Rchild;
        }
     }
}

void feidigui_PostOrder(BiTree root)  //非递归后序
{
    stack<BiTree> s;
    BiTree p,q;
    p=root;q=NULL;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)
        {
            s.push(p);
            p=p->Lchild;
        }
        if(!s.empty())
        {
            p=s.top();
            if(p->Rchild==NULL||p->Rchild==q)   //判断节点何时出栈
            {  
               s.pop();
               printf("%c",p->data);
               q=p;
               p=NULL;
            }
            else
            {
                p=p->Rchild;
            }
        }
    }
}
void LevelOrder(BiTree root)//层序遍历
{
     queue<BiTree> s;
     BiTree p;
     s.push(root);
     while(!s.empty())
     {  
        p=s.front();
        s.pop();
        printf("%c",p->data);
        if(p->Lchild!=NULL)
        {
            s.push(p->Lchild);
        }
        if(p->Rchild!=NULL)
        {
            s.push(p->Rchild);
        }

     }
}
int PostTreeDepth(BiTree root)
{
    int hl,hr,h;
    if(root==NULL)
    return 0;
    else
    {
        hl=PostTreeDepth(root->Lchild);
        hr=PostTreeDepth(root->Rchild);
        h=(hl>hr?hl:hr)+1;
        return h;
    }

}
int main()
{
    BiTree root;
    CreateBiTree(&root);
    printf("二叉树高度:");
    printf("%d",PostTreeDepth(root));
    printf("\n");
    printf("先序：");
    PreOrder(root);
    printf("\n");
    printf("中序:");
    InOrder(root);
    printf("\n");
    printf("后序:");
    PostOrder(root);
    printf("\n");

    printf("非递归：\n");
    printf("先序:");
    feidigui_PreOrder(root);
    printf("\n");
    printf("中序:");
    feidigui_InOrder(root);
    printf("\n");
    printf("后序:");
    feidigui_PostOrder(root);
    printf("\n");
    printf("层序：");
    LevelOrder(root);
    printf("\n");
}