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