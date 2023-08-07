class Solution {
public:
    int climbStairs(int n) {
        int f1=1,f2=2,tmp=0;
        if(n==1){
            return 1;
        }
        if(n==2)
        {
            return 2;
        }
        for(int i=3;i<=n;i++)
        {   tmp=f2;
            f2=f1+f2;
            f1=tmp;
            
        }
        return f2;
    }
};


//完全背包版
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) { // 遍历背包
            for (int j = 1; j <= 2; j++) { // 遍历物品
                if (i - j >= 0) dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }
};
