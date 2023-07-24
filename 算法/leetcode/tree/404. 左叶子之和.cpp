class Solution {
public:
    int sum;
    int sumOfLeftLeaves(TreeNode* root) {
         if(root->left!=NULL&&root->left->right==NULL&&root->left->left==NULL)
         {
             sum+=root->left->val;
         }
         if(root->left) sumOfLeftLeaves(root->left);
         if(root->right) sumOfLeftLeaves(root->right);
         return sum;

    }
};