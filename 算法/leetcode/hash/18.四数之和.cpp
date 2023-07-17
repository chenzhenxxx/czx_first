class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         vector<vector<int>> result;
         sort(nums.begin(),nums.end());
         for(int k=0;k<nums.size();k++)
         {
             if(nums[k] > target && target>=0){
                 break;
             }
             if(k>0&&nums[k]==nums[k-1])
             {
                 continue;
             }
             for(int i = k+1;i<nums.size();i++){
                 if(nums[k] + nums[i] >target && target > 0)
                 {
                     break;
                 }
                 if(i>k+1&&nums[i]==nums[i-1])
                 {
                     continue;
                 }
                 int p = i+1;
                 int q = nums.size()-1;
                 while(p<q){
                     if((long)nums[k]+nums[i]+nums[p]+nums[q]<target){
                         p++;
                     }
                     else if((long)nums[k]+nums[i]+nums[p]+nums[q]>target){
                         q--;
                     }
                     else{
                         result.push_back({nums[k],nums[i],nums[p],nums[q]});
                         p++;
                         q--;
                 while(p<q&&nums[p]==nums[p-1])p++;
                 while(p<q&&nums[q]==nums[q+1])q--;
                     }
                 }
                
             }
         }
         return result;
    }
};