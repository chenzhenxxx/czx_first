//解法1 时间: O(n) 空间:O(n) 
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//        int len=nums.size();
//        vector<int> L(len,0),R(len,0);
//        L[0]=1;
//        for(int i=1;i<len;i++)
//        {
//            L[i]=L[i-1]*nums[i-1];
//        }
//        R[len-1]=1;
//        for(int i=len-2;i>=0;i--)
//        {
//            R[i]=R[i+1]*nums[i+1];
//        }
//        for(int i=0;i<len;i++)nums[i]=L[i]*R[i];
//        return nums;       
//     }
// };
