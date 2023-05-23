//dp
class Solution {
public:
    int countSubstrings(string s) {
          vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
          int result=0;
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
          }
          return result;
    }
};


//双指针
class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            result += extend(s, i, i, s.size()); // 以i为中心
            result += extend(s, i, i + 1, s.size()); // 以i和i+1为中心
        }
        return result;
    }
    int extend(const string& s, int i, int j, int n) {
        int res = 0;
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
            res++;
        }
        return res;
    }
};
