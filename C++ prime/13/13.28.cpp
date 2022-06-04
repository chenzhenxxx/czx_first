#include<bits/stdc++.h>
using namespace std;
class TreeNode {
     
     public:
     TreeNode(const TreeNode&);
     TreeNode():value(string()),count(0),left(nullptr),right(nullptr),use(new size_t(1)){}
     TreeNode& operator=(const TreeNode &t);
     ~TreeNode();

    private:
      string value;
      int count;
      TreeNode *left;
      TreeNode *right;
      size_t *use;
};
TreeNode& TreeNode:: operator=(const TreeNode &t)
{   
    (*t.use)++;
    if(--*use==0)
    {
        delete right;
        delete left;
        delete use;
    }
    value=t.value;
    count=t.count;
    left=t.left;
    right=t.right;
    return *this;
}
TreeNode:: ~TreeNode()
{
   if(--*use==0)
   {
       delete right;
       delete left;
       delete use;
   }
}
