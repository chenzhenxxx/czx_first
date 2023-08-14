class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
     vector<vector<int>> dp(prices.size()+1,vector<int>(2*k+1,0));
     for(int j=1;j<=2*k;j++)
     {   
         if(j%2!=0)
         dp[0][j]=-prices[0];
     }

     for(int i=1;i<prices.size();i++)
     for(int j=0;j<=2*k;j++)
     {   int tmp = prices[i];
         if(j%2!=0) tmp=-tmp;
         if(j==0) dp[i][0]=dp[i-1][0];
         else
         dp[i][j] =max(dp[i-1][j],dp[i-1][j-1]+tmp);
     }
     return dp[prices.size()-1][2*k];
    }
};