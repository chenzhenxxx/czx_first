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
     bool compare(TreeNode*p,TreeNode*q)
    {
        if(p!=NULL&&q==NULL) return false;
        else if(p==NULL&&q!=NULL) return false;
        else if(p==NULL&&q==NULL) return true;
        else if(p->val!=q->val) return false;
        bool a= compare(p->left,q->left);
        bool b=compare(p->right,q->right);
        return a&&b;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL&&subRoot==NULL) return true;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* tree = st.top();
            st.pop();
            if(tree->val==subRoot->val)
            {   
                if(compare(tree,subRoot))
                {
                    return true;
                }
            }
            if(tree->right) st.push(tree->right);
            if(tree->left)st.push(tree->left);
        }
        return false;

    }
};