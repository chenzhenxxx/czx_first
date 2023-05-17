// class Solution {
// public:
//     int maxSubarraySumCircular(vector<int>& nums) {
//           int total=0,cur_max=0,max_sum=nums[0],cur_min=0,min_sum=nums[0];
//           for(int&a : nums){
//               cur_max = max(cur_max+a,a);
//               max_sum = max(max_sum,cur_max);
//               cur_min = min(cur_min+a,a);
//               min_sum = min(min_sum,cur_min);
//               total+=a;
//           }
//           return max_sum >0? max(max_sum,total-min_sum):max_sum;
//     }
// };