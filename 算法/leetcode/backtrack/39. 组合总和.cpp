class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void Sum(vector<int>& candidates,int target,int sum,int startindex)
    {
        //if(sum>target) return;
        if(sum == target)
        {
            result.push_back(path);
            return ;
        }
        for(int i=startindex;i<candidates.size()&&sum+candidates[i]<=target;i++)
        {   path.push_back(candidates[i]);
            Sum(candidates,target,sum+candidates[i],i);
            path.pop_back();
        }
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         sort(candidates.begin(), candidates.end());
         Sum(candidates,target,0,0);
         return result;
    }
};