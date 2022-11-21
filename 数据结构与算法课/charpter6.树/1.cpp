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
void CreateBiTree(BiTree *root)
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
void PostOrder(BiTree root)
{
    if(root)
    {
        PostOrder(root->Lchild);
        PostOrder(root->Rchild);
        printf("%c",root->data);
    }

}
void feidigui_PostOrder(BiTree root)
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
            if(p->Rchild==NULL||p->Rchild==q)
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
void LevelOrder(BiTree root)
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
int main()
{
    BiTree root;
    CreateBiTree(&root);
    PostOrder(root);
    printf("\n");
    feidigui_PostOrder(root);
    printf("\n");
    LevelOrder(root);
}