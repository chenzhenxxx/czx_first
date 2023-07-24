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
    int countNodes(TreeNode* root) {
       queue<TreeNode*> que;
       int ans=0;
       if(root)
       que.push(root);
       while(!que.empty())
       {   
           int size = que.size();
           ans+=size;
           for(int i=0;i<size;i++)
           {    TreeNode * t = que.front();
                que.pop();
               if(t->left) que.push(t->left);
               if(t->right) que.push(t->right);
           }
       }
       return ans;
    }
};

//完全二叉树性质
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
    int countNodes(TreeNode* root) {
       if(root == NULL) return 0;
       int left_len=0;
       int right_len = 0;
       TreeNode* left = root->left;
        TreeNode* right = root->right;
        while(left)
        {
            left = left->left;
            left_len++;
        }
        while(right)
        {
            right = right->right;
            right_len++;
        }
        if(left_len == right_len) return (2<<left_len) -1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};