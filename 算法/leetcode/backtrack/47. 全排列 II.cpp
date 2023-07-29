class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int>& nums, int step,vector<bool> flag)
    {
         if(step==nums.size())
         {
             result.push_back(path);
             return;
         }

         for(int i=0;i<nums.size();i++)
         {
             if(i>0&&nums[i]==nums[i-1]&&flag[i-1]==false||flag[i]==true) continue;
             flag[i]=true;
             path.push_back(nums[i]);
             backtracking(nums,step+1,flag);
             path.pop_back();
             flag[i]=false;

         }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> flag(nums.size(),false);
        sort(nums.begin(),nums.end());
        backtracking(nums,0,flag);
        return result;
    }
};