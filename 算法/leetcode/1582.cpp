class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
       int ans=0;
       for(int i =0;i<mat.size();i++){
           if(accumulate(mat[i].begin(),mat[i].end(),0)==1){
               int sum=0,index=0;
               for(int x=0;x<mat[i].size();x++){
                   if(mat[i][x]==1)
                   {
                       index=x;
                   }
               }
               for(int j=0;j<mat.size();j++)
               {
                   sum+=mat[j][index];
               }
               if(sum==1)
               {
                   ans++;
               }
           }
       }
       return ans;
    }
};