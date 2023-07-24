/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool compare(TreeNode*p,TreeNode*q)
    {
        if(p!=NULL&&q==NULL) return false;
        else if(p==NULL&&q!=NULL) return false;
        else if(p==NULL&&q==NULL) return true;
        else if(p->val!=q->val) return false;
        bool a= compare(p->left,q->left);
        bool b=compare(p->right,q->right);
        return a&&b;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
     if(p==NULL&&q==NULL) return true;
     bool ans = compare(p,q);
     return ans;
    }
};

//迭代版本
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   
    bool isSameTree(TreeNode* p, TreeNode* q) {
     if(p==NULL&&q==NULL) return true;
     queue<TreeNode*> que;
     que.push(p);
     que.push(q);

     while(!que.empty())
     {
         TreeNode* tree1 = que.front();que.pop();
         TreeNode* tree2 = que.front();
         que.pop();
         if(!tree1&&!tree2)
         {
             continue;
         }
         if(!tree1||!tree2||tree1->val!=tree2->val) return false;
         que.push(tree1->left);
         que.push(tree2->left);
         que.push(tree1->right);
         que.push(tree2->right);
     }
     return true;
    }
};