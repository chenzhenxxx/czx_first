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
    vector<vector<int>> levelOrder(TreeNode* root) {
      queue<TreeNode*> qe;
      vector<vector<int>> ans;
      if(root!=NULL) qe.push(root);
      while(!qe.empty()){
          int size = qe.size();
          vector<int> tmp;
          for(int i = 0 ; i < size; i++){
              TreeNode * pr = qe.front();
              qe.pop();
              tmp.push_back(pr->val);
              if(pr->left) qe.push(pr->left);
              if(pr->right) qe.push(pr->right);
          }
           ans.push_back(tmp);
      }
      return ans;
    }
};