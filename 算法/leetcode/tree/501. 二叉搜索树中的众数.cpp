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
    int cnt;
    int max_cnt;
    TreeNode* pre = NULL;
    vector<int> result;
    void searchBST(TreeNode* cur){
          if(cur==NULL) return;
          searchBST(cur->left);
          if(!pre)
          {
              cnt=1;
          }
          else if(pre->val==cur->val)
          {
              cnt++;
          }
          else{
              cnt=1;
          }
          if(cnt==max_cnt)
          {
              result.push_back(cur->val);
          }
          if(cnt>max_cnt)
          {
              max_cnt = cnt;
              result.clear();
              result.push_back(cur->val);
          }
          pre = cur;
          searchBST(cur->right);
    }
    vector<int> findMode(TreeNode* root) {
        searchBST(root);
        return result;
    }
};