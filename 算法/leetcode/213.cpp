//自己做的，错了，没考虑完全
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//          if(nums.size()==1)
//          {
//              return nums[0];
//          }
//          if(nums.size()==2)
//          {
//              return max(nums[0],nums[1]);
//          }
//          if(nums.size()==3)
//          {
//              int a=max(nums[0],nums[1]);
//              a=max(a,nums[2]);
//              return a;
//          }
//          int dp1[nums.size()];
//          dp1[0]=0;
//          dp1[1]=nums[1];
//          dp1[2]=0;
//          for(int i=3;i<nums.size();i++){
//              dp1[i]=max(dp1[i-1],dp1[i-2]+nums[i]);
//          }
//          int dp2[nums.size()];
//          dp2[0]=nums[0];
//          dp2[1]=0;
//          dp2[2]=nums[2]+dp2[0];
//          for(int i=3;i<nums.size()-1;i++){
//              dp2[i]=max(dp2[i-1],dp2[i-2]+nums[i]);
//          }
//          return max(dp1[nums.size()-1],dp2[nums.size()-2]);
//     }
// };