class Solution {
public:
    int depth;
    int ans;
    void getDepth(TreeNode*root,int dep)
    {   int flag=0;
        
        if(root!=NULL&&root->left==NULL&&root->right==NULL){
            if(dep>depth)
            {
                ans=root->val;
                depth=dep;
            }
        }
    
        
        if(root->left)getDepth(root->left,dep+1);
        if(root->right)getDepth(root->right,dep+1);
    }
    int findBottomLeftValue(TreeNode* root) {
         ans = root->val;
         getDepth(root,1);
         return ans;

    }
};