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
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(root== NULL ) return NULL;
       if(root->val == key)
       {
           if(root->left==NULL&& root->right==NULL)
           {
               delete root;
               return NULL;
           }
           else if(root->left&&!root->right)
           {
               TreeNode* node = root->left;
               delete root;
               return node;
           }
           else if(!root->left&&root->right)
           {
               TreeNode* node = root->right;
               delete root;
               return node;
           }
           else if(root->left&&root->right){
               TreeNode*node = root->right;
               while(node->left)
               {
                   node = node->left;
               }
               node->left = root->left;
               node = root->right;
               delete root;
               return node;
           }
           
       }
       if(root->val>key) root->left = deleteNode(root->left,key);
       if(root->val<key) root->right = deleteNode(root->right,key);
       return root;
     }
};