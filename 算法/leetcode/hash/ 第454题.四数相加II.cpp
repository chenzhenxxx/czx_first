class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {     
        int cnt=0;
        unordered_map<int,int> umap;
        for(auto &a:nums1){
            for(auto &b:nums2){
                umap[a+b]++;
            }
        }

        for(auto &c:nums3){
            for(auto &d:nums4){
                if(umap.find(-(c+d))!=umap.end())
                {
                    cnt+=umap[-(c+d)];
                }
            }
        }
        return cnt;
    }
};