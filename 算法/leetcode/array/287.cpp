class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=1,r=n-1;
        int ans=1;
        while(l<=r)
        {   int cnt=0;
            int mid=(l+r)>>1;
            for(int i=0;i<n;i++)
            {
               cnt+= mid>=nums[i];
            }
            if(cnt<=mid){
                l=mid+1;
            }
            else{
                r=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};
