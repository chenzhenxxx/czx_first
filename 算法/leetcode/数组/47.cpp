class Solution {
    private:vector<int> vis;
public:
    void backtrack(vector<int>&num,vector<vector<int>>&ans,int len,vector<int>&perm)
    {
        if(len==num.size())
        {
            ans.emplace_back(perm);
            return;
        }
        for(int i=0;i<num.size();i++)
        {
            if(vis[i]||i>0&&num[i]==num[i-1]&&!vis[i-1]) continue;
            perm.emplace_back(num[i]);
            vis[i]=1;
            backtrack(num,ans,len+1,perm);
            vis[i]=0;
            perm.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
              vector<vector<int>> res;
              vector<int>perm;
              sort(nums.begin(),nums.end());
              vis.resize(nums.size());
         backtrack(nums,res,0,perm);
         return res;
    }
};