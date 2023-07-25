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
    TreeNode* traserval(vector<int>& preorder,vector<int>&inorder)
    {
           if(preorder.size()==0) return NULL;
           int value = preorder[0];
           TreeNode* root = new TreeNode(value);

           if(preorder.size()==1) return root;

           int index=0;
           for(index=0;index<inorder.size();index++)
           {
               if(inorder[index]==value)
               {
                   break;
               }
           }

           vector<int> inorder_first(inorder.begin(),inorder.begin()+index);
           vector<int> inorder_second(inorder.begin()+index+1,inorder.end());
           vector<int> preorder_first(preorder.begin()+1,preorder.begin()+inorder_first.size()+1);
           vector<int> preorder_second(preorder.begin()+inorder_first.size()+1,preorder.end());
           root->left = traserval(preorder_first,inorder_first);
           root->right = traserval(preorder_second,inorder_second);
           return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         if(preorder.size()==0||inorder.size()==0) return NULL;
         
         return traserval(preorder,inorder);
    }
};