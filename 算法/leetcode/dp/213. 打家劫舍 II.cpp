class Solution {
public:


    int rob1(vector<int>& nums) {
      if(nums.size()==1)
      {
          return nums[0];
      }
      int dp[nums.size()];
      dp[0]=nums[0];
      dp[1]=max(nums[0],nums[1]);
      for(int i=2;i<nums.size();i++){
          dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
      }
      return dp[nums.size()-1];
    }

    int rob(vector<int>& nums) {
         if(nums.size()==1)
         {
             return nums[0];
         }
         vector<int> s;
         for(int i=0;i<nums.size()-1;i++)
         {
             s.push_back(nums[i]);
         }
         vector<int> t;
         for(int i=1;i<nums.size();i++)
         {
             t.push_back(nums[i]);
         }
         int max1=rob1(s);
         int max2=rob1(t);
         return max(max1,max2);
    }

};