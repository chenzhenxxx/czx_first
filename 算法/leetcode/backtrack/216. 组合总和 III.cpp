class Solution {
public:
   vector<vector<int>> result;
   vector<int> path;
   void backtracking(int k,int n,int start,int sum)
   {   if(sum>n||path.size()>k)
       return;
       else if(sum==n&&path.size()==k)
       {
           result.push_back(path);
           return ;
       }
       for(int i=start;i<=9-(k-path.size())+1;i++)
       {
           path.push_back(i);
           backtracking(k,n,i+1,sum+i);
           path.pop_back();

       }
   }
    vector<vector<int>> combinationSum3(int k, int n) {
          backtracking(k,n,1,0);
          return result;
    }
};