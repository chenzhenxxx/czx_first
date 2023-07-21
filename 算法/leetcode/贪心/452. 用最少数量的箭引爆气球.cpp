class Solution {
public:
    static bool cmp(const  vector<int> &a,const vector<int>&b)
    {
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
       if(points.size()==0)
       {
           return 0;
       }
       sort(points.begin(),points.end(),cmp);
       int minn = points[0][1];
       int result = 1;
       for(int i=1;i<points.size();i++)
       {
            if(points[i][0]>minn)
            {
                result++;
                minn = points[i][1];
            }
            else{
                minn = min(minn,points[i][1]); 
            }
       }
       return result;
    }
};