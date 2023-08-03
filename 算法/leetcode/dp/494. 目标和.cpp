//回溯
class Solution {
public:
    int ans=0;
    void backtarcking(vector<int>&nums,int target,int index,int sum)
    {   
        if(index==nums.size())
        {   
            if(target==sum) ans++;
            return;
        }
        else{
            backtarcking(nums,target,index+1,sum+nums[index]);
            backtarcking(nums,target,index+1,sum-nums[index]);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
         backtarcking(nums,target,0,0);
         return ans;
    }
};


//dp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
int sum = 0;
     for(int i = 0;i < nums.size();i++) sum += nums[i];
vector<int> dp(sum+1,0);
     if(abs(target) > sum) return 0;
     if((target + sum) % 2 == 1) return 0;
int bagSize = (target + sum) /2;
     dp[0] =1;
     for(int i = 0; i < nums.size(); i++) {
         for(int j = bagSize; j>= nums[i]; j--)
         {
             dp[j] += dp[j-nums[i]];
         }
     }
     return dp[bagSize];
    }
};