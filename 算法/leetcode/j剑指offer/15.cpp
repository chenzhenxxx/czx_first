// 自己写的第一版，时间复杂度on3,超时了
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//       vector<vector<int>> m;
//       int flag=0;
//       sort(nums.begin(),nums.end());
//       cout<<nums[0]<<endl;
//       for(int i=0;i<nums.size();i++)
//       {
//           if(nums[i]!=0)
//           {   flag=1;
//               break;
//           }
//       }
//       if(flag==0)
//       {
//           m.push_back({0,0,0});
//           return m;
//       }
//       for(int i=0;i<nums.size()-2;i++)
//       {   if(nums[i]>0)
//           {
//               break;
//           }
//           if(i>0){
//               if(nums[i]==nums[i-1])
//               {
//                   continue;
//               }
//           }
//       for(int j=i+1;j<nums.size()-1;j++)
//       {    
//           if(j>i+1){
//               if(nums[j]==nums[j-1])
//               {
//                   continue;
//               }
//           }
//           for(int k=j+1;k<nums.size();k++){
//               if(k>j+1){
//               if(nums[k]==nums[k-1])
//               {
//                   continue;
//               }
//           }
//               if((nums[i]+nums[j]+nums[k])==0)
//               m.push_back({nums[i],nums[j],nums[k]});
//           }
//       }
//       }
//       return m;
//     }
// };


//题解双指针
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         sort(nums.begin(),nums.end());
//         int len=nums.size();
//         if(len<3){
//             return ans;
//         }
//         for(int i=0;i<len;i++)
//         {
//             if(nums[i]>0){
//                 break;
//             }
//             int l=i+1;
//             int r=len-1;
//             while(l<r){
//                 if(nums[i]+nums[l]+nums[r]==0){
                    
//                     ans.push_back({nums[i],nums[l],nums[r]});
//                     l++;
//                     r--;
//                     while(l<r&&nums[l]==nums[l-1]) l++;
//                     while(l<r&&nums[r]==nums[r+1]) r--;
//                 }
//                 else if(nums[i]+nums[r]+nums[l]>0)
//                     {   
//                         r--;
//                     }
//                 else
//                     {   
//                         l++;
//                     }
                
//             }
//             while(i+1<len&&nums[i]==nums[i+1]){
//                 i++;
//             }
//         }
//         return ans;
//     }
// };