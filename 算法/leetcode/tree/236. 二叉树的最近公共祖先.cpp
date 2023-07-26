class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root==q || root == p || root==NULL) return root;

            TreeNode* left = lowestCommonAncestor(root->left,p,q);
            TreeNode* right = lowestCommonAncestor(root->right,p,q);
            if(left&&right) return root;
            else if(!left&&right) return right;
            else if(!right&&left) return left;
            else return NULL;

            
    }
};