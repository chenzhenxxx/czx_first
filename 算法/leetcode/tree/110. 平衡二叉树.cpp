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
int getHeight(TreeNode* node)
    {
        if(node==NULL){
            return 0;
        }
        int left = getHeight(node->left);
        if(left ==-1) return -1;
        int right = getHeight(node->right);
        if(right ==-1) return -1;
        return abs(left-right)>1?-1:1+max(left,right);

    }
    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
};