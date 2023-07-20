class Solution {
public:
    static bool cmp(int a,int b){
        return abs(a)>abs(b);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int cnt=0;
        int result=0;
        sort(nums.begin(),nums.end(),cmp);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0&&k>0)
            {
                nums[i]*=-1;
                k--;
            }
        }
        if(k%2==1) nums[nums.size()-1]*=-1;
        for(int i=0;i<nums.size();i++)
        {
            result+=nums[i];
        }
        return result;
    }
};