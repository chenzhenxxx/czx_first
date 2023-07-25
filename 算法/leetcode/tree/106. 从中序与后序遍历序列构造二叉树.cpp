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
public: TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
            if(postorder.size()==0) return NULL;
            int rootValue = postorder[postorder.size()-1];
            TreeNode * root = new TreeNode(rootValue);
            if(postorder.size()==1) return root;
            int index = 0 ;
            for(index=0;index<inorder.size();index++)
            {
                if(inorder[index]==rootValue)
                {
                      break;
                }
            }
             postorder.resize(postorder.size() - 1);
            vector<int> inorder_first(inorder.begin(),inorder.begin()+index);
            vector<int> inorder_second(inorder.begin()+index+1,inorder.end());
            vector<int> postorder_first(postorder.begin(),postorder.begin()+inorder_first.size());
            vector<int> post_second(postorder.begin()+inorder_first.size(),postorder.end());
            root->left=traversal(inorder_first,postorder_first);
            root->right = traversal(inorder_second,post_second);
            return root;
    }
     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, postorder);
    }
};