class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b)->bool
       {if(a[0]==b[0])
       return a[1]<b[1];
       else return a[0]<b[0];});
       vector<vector<int>>ans;
       int left=intervals[0][0];
       int right=intervals[0][1];
       for(int i=1;i<intervals.size();i++)
       {
           if(right>=intervals[i][0])
           {
           if(right<intervals[i][1])
           right=intervals[i][1];
           }
           else
           {
              ans.push_back({left,right});
              left=intervals[i][0];
              right=intervals[i][1];
           }
       }
       if(ans.empty()||left>ans[ans.size()-1][1])ans.push_back({left,right});
       return ans;
    }
};