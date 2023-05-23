//自己写的第一版超时里，看了官方题解发现也是拆分，但是他通过一个哈希表存储里
//A+B,在进行C+D的时候进行查找哈希表
// class Solution {
// public:
//     int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {     
//         int ans=0;
//              vector<int> sum1;
//              vector<int> sum2;
//              for(int i=0;i<nums1.size();i++)
//              {
//                  for(int j=0;j<nums2.size();j++)
//                  {
//                      sum1.push_back(nums1[i]+nums2[j]);
//                  }
//              }

//              for(int i=0;i<nums3.size();i++)
//              {
//                  for(int j=0;j<nums4.size();j++)
//                  {
//                      sum2.push_back(nums3[i]+nums4[j]);
//                  }
//              }
//              sort(sum1.begin(),sum1.end());
//              sort(sum2.begin(),sum2.end());
//              for(int i=0;i<sum1.size();i++)
//              {   
//                  for(int j=0;j<sum2.size();j++)
//                  {      
                  
//                         if(sum1[i]+sum2[j]>0)
//                         continue;
//                         else if(sum1[i]+sum2[j]==0)
//                         {
//                             ans++;
//                         }
//                  }
//              }
//              return ans;
//     }
// };


//官方题解

// class Solution {
// public:
//     int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {     
//         int ans=0;
//             unordered_map<int,int> countAB;
//              for(int i=0;i<nums1.size();i++)
//              {
//                  for(int j=0;j<nums2.size();j++)
//                  {
//                      ++countAB[nums1[i]+nums2[j]];
//                  }
//              }

//              for(int i=0;i<nums3.size();i++)
//              {
//                  for(int j=0;j<nums4.size();j++)
//                  {
//                      if(countAB[-(nums3[i]+nums4[j])])
//                      {
//                          ans+=countAB[-(nums3[i]+nums4[j])];
//                      }
//                  }
//              }
            
//              return ans;
//     }
// };