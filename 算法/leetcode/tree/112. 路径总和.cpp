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
    bool flag=false;
    void getEQU(TreeNode* root ,int sum,int targetSum)
    {   cout<<sum<<endl;
        if(sum==targetSum&&root->left==NULL&&root->right==NULL){
           flag=true;
           return ;
        }
        if(root->left){
            getEQU(root->left,sum+root->left->val,targetSum);
        }
        if(root->right){
            getEQU(root->right,sum+root->right->val,targetSum);
        }
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
       if(root==NULL) return false;
       getEQU(root,root->val,targetSum);
       return flag;
    }
};