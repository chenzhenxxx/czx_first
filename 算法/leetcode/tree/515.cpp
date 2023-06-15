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
    vector<int> largestValues(TreeNode* root) {
          queue<TreeNode*> que;
            vector<int> ans;
            if(root!=NULL) que.push(root);
            while(!que.empty()){
                int size = que.size();
                 int maxx = que.front()->val;
                for(int i = 0;i <size ;i++){
                   TreeNode * node = que.front();
                   que.pop();
                   maxx = maxx > node->val ? maxx : node->val;
                   if(node->left) que.push(node->left);
                   if(node->right)que.push(node->right); 
                }
                ans.push_back(maxx);
               
            } 
            
            return ans;
    }
};