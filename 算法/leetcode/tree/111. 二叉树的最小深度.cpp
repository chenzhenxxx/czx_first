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
int result=999999;
    void getdepth(TreeNode* node,int depth)
    {   if(node->left==NULL&&node->right==NULL)
        result = result<depth?result:depth;
        if(node->left)
        {
            depth++;
            getdepth(node->left,depth);
            depth--;
        }
        if(node->right)
        {
            depth++;
            getdepth(node->right,depth);
            depth--;
        }
        return;
    }
    int minDepth(TreeNode* root) {
            if(root==NULL) return 0;
            getdepth(root,1);
            return result;
    }
            
    
};