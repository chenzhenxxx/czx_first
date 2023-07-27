class Solution {
public:
    static bool cmp(const vector<int>&a,const vector<int>&b)
    {
        return a[0]<b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         sort(intervals.begin(),intervals.end(),cmp);
         int minn=intervals[0][1];
         int result = 0;
         for(int i=1;i<intervals.size();i++)
         {
              if(intervals[i][0]<minn)
              {   result++;
                  minn = min(minn,intervals[i][1]);
              }
              else{
                  minn =intervals[i][1];
              }
         }
         return result;
    }
};