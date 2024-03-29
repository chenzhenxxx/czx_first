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
    int maxDepth(TreeNode* root) {
          queue<TreeNode*> que;
            vector<int> ans;
            if(root!=NULL) que.push(root);
            int len=0;
            while(!que.empty()){
                int size = que.size();
                for(int i = 0;i <size ;i++){
                   TreeNode * node = que.front();
                   que.pop();
                   if(node->left) que.push(node->left);
                   if(node->right)que.push(node->right); 
                }
                len++;
            } 
            return len;
    }
};