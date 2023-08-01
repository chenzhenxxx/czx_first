class Solution {
public:
    int fib(int n) {
      int a1=0;
      int a2=1;
      int a3;
      if(n==0) return a1;
      else if(n==1) return a2;
      else
      {
          n-=2;
          for(int i=0;i<=n;i++)
          {
              a3=a2+a1;
              a1=a2;
              a2=a3;
          }
      }
      return a3;
    }
};