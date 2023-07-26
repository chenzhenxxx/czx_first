//用下标当参数节省空间
class Solution {
private:
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left >= right) return nullptr;
        int maxValueIndex = left;
        for (int i = left + 1; i < right; ++i) {
            if (nums[i] > nums[maxValueIndex]) maxValueIndex = i;
        }

        TreeNode* root = new TreeNode(nums[maxValueIndex]);

        root->left = traversal(nums, left, maxValueIndex);

        root->right = traversal(nums, maxValueIndex + 1, right);

        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
};

//自己写的效率很低
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
    TreeNode* bigtree(vector<int> & nums)
    {   if(nums.size()==0) return NULL;
        int index=0;
        int maxx=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>maxx)
            {
                maxx= nums[i];
                index = i;
            }
        }
        TreeNode* root = new TreeNode(maxx);
        if(nums.size()==1) return root;

        vector<int> first(nums.begin(),nums.begin()+index);
        vector<int> second(nums.begin()+index+1,nums.end());
        root->left = bigtree(first);
        root->right = bigtree(second);
        return root;

    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      if(nums.size()==0) return NULL;
      return bigtree(nums);
    }
};