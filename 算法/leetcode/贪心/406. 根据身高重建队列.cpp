class Solution {
public:
    static bool cmp(const vector<int> &a,const vector<int> &b)
    {
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
       vector<vector<int>> ans;
       sort(people.begin(),people.end(),cmp);
       for(int i=0;i<people.size();i++)
       {
           int pos = people[i][1];
           ans.insert(ans.begin()+pos,people[i]);
       }
       return ans;
    }
};