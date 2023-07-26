class Solution {
public:
    int result = INT_MAX;
    TreeNode* pre=NULL;
    void judge(TreeNode* root )
   {
      if(!root) return;
       
      judge(root->left);
      if(pre){
          result = min(result,root->val-pre->val);
      }
      pre= root;
      judge(root->right);
      return;

    }

    int getMinimumDifference(TreeNode* root) {
        judge(root);
        return result;
    }
};