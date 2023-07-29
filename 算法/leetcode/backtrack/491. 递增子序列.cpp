class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int>& nums,int start)
    {    if(path.size()>=2)
         result.push_back(path);
         
         //if(start>=nums.size()) return;
          int book[201]={0};
         for(int i=start;i<nums.size();i++)
         {
             if(book[nums[i]+100]==1) continue;
             if(path.size()==0||nums[i]>=path.back())
             {
                 path.push_back(nums[i]);
                 book[nums[i]+100]=1;
                 backtracking(nums,i+1);
                 path.pop_back();
             }
         }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums,0);
        return result;
    }
};