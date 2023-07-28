class Solution {
public:
    vector<int> path;
    bool book[1100];
    vector<vector<int>> result;
    void Sum(vector<int>& candidates,int target,int start,int sum)
    {
     
        if(sum==target)
        {
            result.push_back(path);
            return;
        }
        for(int i=start;i<candidates.size()&&sum+candidates[i]<=target;i++)
        {   
            if(i>0&&candidates[i]==candidates[i-1]&&book[i-1]==false)
            continue;
            book[i]=true;
            path.push_back(candidates[i]);
            Sum(candidates,target,i+1,sum+candidates[i]);
            path.pop_back();
            book[i]=false;
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        memset(book,false,sizeof(book));
        sort(candidates.begin(),candidates.end());
        Sum(candidates,target,0,0);
        return result;
    }
};