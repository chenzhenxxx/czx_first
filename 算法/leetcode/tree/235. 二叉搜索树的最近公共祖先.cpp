lass Solution {
public:
    TreeNode* traveral(TreeNode* root,TreeNode*p,TreeNode*q)
    {
         if(root== NULL) return NULL;

             if(root->val>p->val&&root->val>q->val) 
             {
                TreeNode* left = lowestCommonAncestor(root->left,p,q);
                if(left)
                {
                    return left;
                }
             }
             if(root->val<p->val&&root->val<q->val) 
             {
                TreeNode* right = lowestCommonAncestor(root->right,p,q);
                if(right)
                {
                    return right;
                }
             }
             return root;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          
             return traveral(root,p,q);
    }
};