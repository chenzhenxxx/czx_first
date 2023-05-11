#iclude<iostream>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int h_0=0;
       int l_0=0;
       int n=matrix.size();
       int m=matrix[0].size();
       for(int i=0;i<n;i++)
       if(matrix[i][0]==0)
       {
           l_0=0;
           break;
       }
       for(int i=0;i<m;i++)
       if(matrix[0][i]==0)
       {
           h_0=0;
           break;
       }
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(matrix[i][j]==0)
               {
                   matrix[i][0]=matrix[0][j]=0;
               }
           }
       }
       for(int i=0;i<n;i++)
       {
           if(matrix[i][0]==0)
           {
               for(int j=0;j<m;j++)matrix[i][j]=0;
            
           }

       }

            for(int i=0;i<m;i++)
       {
           if(matrix[0][m]==0)
           {
               for(int j=0;j<n;j++)matrix[j][i]=0;
            
           }

       }
       if(l_0==0)for(int i=0;i<n;i++)matrix[i][0]=0;
       if(h_0==0)for(int i=0;i<m;i++)matrix[0][i]=0;
}
};