//自己的，很丑但是能过
// class Solution {
// public:
//     int deleteAndEarn(vector<int>& nums) {
//        int mmax=0;
//        if(nums.size()==0)
//        {
//            return 0;
//        }
//        for(int i=0;i<nums.size();i++)
//        {
//            if(mmax<nums[i]){
//                mmax=nums[i];
//            }
//        }
//        int* all = new int[mmax+1];
//        for(int i=0;i<mmax+1;i++)
//        {
//            all[i]=0;
//        }
//        for(int i:nums){
//            all[i]++;
//        }
//        int *dp = new int [mmax+1];
//        dp[0]=0;
//        dp[1]=all[1]*1;
//        for(int i=2;i<=mmax;i++)
//        {
//            dp[i]=max(dp[i-1],dp[i-2]+all[i]*i);
//        }
//        return dp[mmax];
//     }
// };

//佬的
// class Solution {
// public:
//     int deleteAndEarn(vector<int>& nums) {
//         if(nums.size() < 1) return 0;
//         int maxn = 0;
//         for(int it : nums)
//             maxn = max(maxn, it);
//         vector<int> cnt(maxn+1), dp(maxn+1);
//         for(int it : nums)
//             cnt[it]++;
//         dp[1] = cnt[1];
//         for(int i = 2; i <= maxn; i++)
//             dp[i] = max(dp[i-1], dp[i-2] + cnt[i] * i);
//         return dp[maxn];
//     }
// };