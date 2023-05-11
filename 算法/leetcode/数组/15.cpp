class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                     while(j<k&&nums[k]==nums[k+1])k--;
                     while(j<k&&nums[j]==nums[j-1])j++;
                }
                else if(nums[i]+nums[j]+nums[k]>0)
                { 
                k--;

                }
                else if(nums[i]+nums[j]+nums[k]<0)
                { j++;
                }
                    
            }
            while(i<nums.size()-1&&nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};