#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct BinTreeNode
{
    T data;
    BinTreeNode<T> *leftChild,*rightChild;
    BinTreeNode() : leftChild(NULL),rightChild(NULL) {}  // 无参构造函数
    BinTreeNode(T x, BinTreeNode<T> *l=NULL,BinTreeNode<T> *r=NULL) :data(x),leftChild(l),rightChild(r) {}
};

template <typename T>
class Binarytree
{
   public:
   //构造函数
   Binarytree() : root(NULL) {}
   Binarytree(T value) :root(NULL),RefValue(value) {}
   //析构函数
   ~Binarytree();
   // 拷贝构造函数
   Binarytree(Binarytree<T> &s);
   //创建二叉树
   void CreateBinTree();
   void CreateBinTree_PreOrder();
   void CreateBinTreeBy_Pre_In(const char *pre,const char * in);
   void CreateBinTreeBy_Post_In(const char *post,const char * in);

   //遍历（递归）
   void PreOrder();
   void InOrder();
   void PostOrder();

   //遍历（非递归）
   void PreOrder_NoRecurve();
   void InOrder_NoRecurve();
   void PostOrder_NoRecurve();

   Binarytree<T> *getRoot();
   Binarytree<T> *Parent(Binarytree<T> *current);
   BinTreeNode<T> *LeftChild(BinTreeNode<T> *current);
   BinTreeNode<T> *RightChild(BinTreeNode<T> *current);

   //销毁函数
   void Destory();
   //判断两棵二叉树是否相等
   bool operator==(Binarytree<T> &s);
   //计算节点数
   int Size();
   //计算高度
   int Height();
   //判断空
   bool Empty();
   //输出二叉树
   void PrintBinTree();
   //翻转二叉树
   void InvertTree();


private: 
    Binarytree<T> *root;
    T RefValue;  
protected:
    void CreateBinTree(BinTreeNode<T> *&BT)
    {   
        stack <BinarytreeNode<T>> s;
        BT=NULL;
        BinTreeNode<T> * p;
        BinTreeNode<T> * q;
        int k=0;
        T ch;
        cin>>ch;
        while(ch!=RefValue)
        {
            switch(ch)
            {
                case '(': 
                  s.push(p); //根节点
                  k=1;//左子树
                  break;
                case ')':
                  s.pop(); //这个子树结束，将栈里的根节点退出
                  break;
                case ',':
                  k=2;//右子树
                  break;

                default:
                  p=new BinarytreeNode<T>(ch);
                  if(BT == NULL)
                  {
                    BT=p;
                  }
                  else if (k==1)
                  {
                    q=s.top();
                    q->leftChild=p;
                  }
                  else if(k==2)
                  {
                    q=s.top();
                    q->rightChild=p;
                  }

            }
            cin>>ch;
        }
        
    }
    void CreateBinTree_PreOrder(BinTreeNode<T> *&subTree)
    {
        T item;
        cin>>item;
        if(item!=RefValue)
        {
           subTree = new BinTreeNode<T>(item);
            if(subTree==NULL)
            {
               cout << "空间分配错误！" << endl;
                exit(1);
            }
            CreateBinTree_PreOrder(subTree->leftChild);
            CreateBinTree_PreOrder(subTree->rightChild);
        }
        else{
          subTree=NULL;
        }
    }
    void CreateTreeBy_Pre_In(BinTreeNode<T> *&cur ,const char *pre,const char *in,int n)
    {
       if (n<=0)
       {
         cur=NULL;
         return; 
       }
       int k=0;
       while(pre[0]!=in[k])
       {
        k++;
       }
       cur=new BinTreeNode<T>(in[k]);
       CreateBinTreeBy_Pre_In(cur->leftChild,pre+1,in,k);
       CreateBinTreeBy_Pre_In(cur->rightChild,pre+k+1,in+k+1,n-k-1);
    }

};
