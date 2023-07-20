class Solution {
public:
    int candy(vector<int>& ratings) {
         vector<int> cdy(ratings.size(),1);
         for(int i=0;i<ratings.size()-1;i++)
         {
             if(ratings[i+1]>ratings[i])
             {
                 cdy[i+1] = cdy[i] +1; 
             }
         }

         for(int i=ratings.size()-2;i>=0;i--)
         {
             if(ratings[i]>ratings[i+1])
             {
                 cdy[i] =max(cdy[i],cdy[i+1]+1);
             }
         }
         int result = 0;
         for(int i=0;i<cdy.size();i++)
         result += cdy[i];
         
         return result;
    }

};