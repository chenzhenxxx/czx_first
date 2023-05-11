class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans(m*n);
        
        int cnt = 0;
        int flag = 0;
        int i=0,j=0;
        int tmplj=0,tmphj=m-1,tmpli=0,tmphi=n-1;
        while(1){

               if(flag == 0 ){
                   ans[cnt++] = matrix[i][j];
                   j++;
                   
                   if(j>tmphj)
                   {
                       j--;
                       i++;
                       flag=1;
                       tmphj--;
                   }
               }
                
                  if(cnt>=m*n){
                  break;
              }
               if(flag == 1){
                   ans[cnt++] = matrix[i][j];
                   i++;
                   if(i>tmphi){
                       i--;
                       j--;
                       flag = 2;
                       tmphi--;
                   }
               }
                 if(cnt>=m*n){
                  break;
              }
               if( flag == 2){
                  ans[cnt++] = matrix[i][j];
                  j--;
                  if(j<tmplj){
                      j = tmplj;
                      i--;
                      flag = 3;
                      tmplj++;
                  }
               }

                 if(cnt>=m*n){
                  break;
              }
               if(flag == 3){
                   ans[cnt++] = matrix[i][j];
                   i--;
                   if(i==tmpli)
                   {     i++;
                         j++;
                         flag=0;
                         tmpli++;
                   }
               }
                 if(cnt>=m*n){
                  break;
              }
            }
            return ans;
    }
};