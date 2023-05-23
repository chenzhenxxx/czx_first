class Solution {
public:
    string longestPalindrome(string s) {
      vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
          int max_len=0;
          int result=0;
          int left=0;
          for(int i=s.size()-1;i>=0;i--)
          for(int j=i;j<s.size();j++){
              if(s[i]==s[j]){
                  if(j-i<=1)
                  {
                      result++;
                      dp[i][j]=true;
                  }
                  else if(dp[i+1][j-1])
                  {
                      result++;
                      dp[i][j]=true;

                  }
              }
              if(dp[i][j]&&j-i+1>max_len)
                {
                    max_len=j-i+1;
                    left=i;
                }
          }
          
          return s.substr(left,max_len);
    }
};