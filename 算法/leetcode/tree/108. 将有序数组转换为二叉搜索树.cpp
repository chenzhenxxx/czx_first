class Solution {
public:
    TreeNode* traversal(vector<int>& nums,int left,int right)
    {
         if(left>right) return NULL;
         int mid =left + (right-left)/2;
         TreeNode* root = new TreeNode(nums[mid]);
         root->left = traversal(nums,left,mid-1);
         root->right = traversal(nums,mid+1,right);
         return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traversal(nums,0,nums.size()-1);
    }
};