class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int>& nums,int start,vector<bool> flag)
    {    result.push_back(path);
         if(start>=nums.size()) return;

         for(int i=start;i<nums.size();i++)
         {   
            if(i>0&&nums[i]==nums[i-1]&&flag[i-1]==false) continue;
             flag[i]=true;
             path.push_back(nums[i]);
             backtracking(nums,i+1,flag);
             path.pop_back(); 
             flag[i]=false;
         }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          vector<bool> flag(nums.size(),false);
          sort(nums.begin(),nums.end());
          backtracking(nums,0,flag);
          return result;
    }
};