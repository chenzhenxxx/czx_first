class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
           vector<int> ans;
           deque<int> qu;

           for(int right=0;right<nums.size();right++)
           {
               while(!qu.empty()&&nums[right]>=nums[qu.back()]){
                   qu.pop_back();
               }
               qu.push_back(right);

               int left=right-k+1;
               while(left>qu.front())qu.pop_front();

               if(right+1>=k)
               ans.push_back(nums[qu.front()]);
           }
           return ans;
    }
};