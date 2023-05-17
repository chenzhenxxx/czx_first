// #include<cmath>
// class Solution {
// public:
//     vector<int> minOperations(string boxes) {
//           vector<int> ans;
//           int len = boxes.size();
//           int sum=0;
//           for(int i=0;i<len;i++){
//               sum=0;
//             for(int j=0;j<len;j++)
//               if(boxes[j]=='1'&&i!=j)
//               {
//                  sum+=abs(i-j);
//               }
//               ans.push_back(sum);
//           }
//           return ans;
//     }
// };