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
    void traversal(TreeNode* root,vector<int> & ans){
        if(root == NULL){
            return;
        } 
        traversal(root->left,ans);
        ans.push_back(root->val);
        traversal(root->right,ans);

    }
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int>result;
       traversal(root,result);
       return result;
    }
};


非递归版本:
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
    
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int>result;
       stack<TreeNode*> st;
       TreeNode *pr = root;
       if(root == NULL) return result;
       while(!st.empty() || pr !=NULL){
           if (pr !=NULL){
               st.push(pr);
               pr = pr->left;
           }
           else{
               pr = st.top();
               st.pop();
               result.push_back(pr->val);
               pr = pr ->right;
           }
       }
       return result;
    }
};