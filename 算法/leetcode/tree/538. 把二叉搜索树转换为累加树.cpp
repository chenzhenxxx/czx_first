class Solution {
public:
    int value;
    void traserval(TreeNode* root)
    {
          if(root==nullptr) return;
          traserval(root->right);
          value+=root->val;
          root->val = value;
          traserval(root->left);
          return;
    }
    TreeNode* convertBST(TreeNode* root) {
      if(root == NULL) return NULL;
      traserval(root);
      return root;
    }
};