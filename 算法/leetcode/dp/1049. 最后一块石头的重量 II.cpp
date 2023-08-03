class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int target =0;
        int sum =0;
        for(auto&i:stones) sum+= i;
        target = sum/2;
        vector<int> dp(target+1,0);

        for(int i=0;i<stones.size();i++)
        {
            for(int j=target;j>=stones[i];j--)
            {
                dp[j] = max(dp[j],dp[j-stones[i]]+stones[i]);
            }
        }
        return sum-2*dp[target];
    }
};