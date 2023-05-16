class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> num_set;
       for(const int&num:nums)
       num_set.insert(num);
       int ans=0;
       for(const int&num:num_set)
       {
           if(!num_set.count(num-1))
           {
               int cur_num=num;
               int tmp=1;
           
           while(num_set.count(cur_num+1))
           {   
               tmp++;
               cur_num=cur_num+1;
           }
           ans=max(ans,tmp);
           }
       }
       return ans;
       }
};