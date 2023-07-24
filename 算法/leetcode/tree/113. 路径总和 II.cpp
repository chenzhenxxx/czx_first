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
    vector<vector<int>> result;
    vector<int> path;
    void getAllPath(TreeNode* root,int sum)
    {   
        if(!root->left&&!root->right&&sum==0)
        {
            result.push_back(path);
        }
        if(root->left)
        {
            path.push_back(root->left->val);
            getAllPath(root->left,sum-root->left->val);
            path.pop_back();
        }
        if(root->right)
        {
            path.push_back(root->right->val);
            getAllPath(root->right,sum-root->right->val);
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return result;
        path.push_back(root->val);
        getAllPath(root,targetSum-root->val);
        return result; 
    }
};