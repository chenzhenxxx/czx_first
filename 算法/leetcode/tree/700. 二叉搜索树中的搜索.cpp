class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
       TreeNode* result =NULL;
       if(root==NULL||root->val == val) return root;
       else if(root->val>val)
       {   
           result = searchBST(root->left,val);
       }
       else 
       {
           result = searchBST(root->right,val);
       }
        return result;
    }
};