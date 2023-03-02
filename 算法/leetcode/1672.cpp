class Solution {  //自己
public:  
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
      for(auto i =accounts.begin();i != accounts.end();i++){
           int max=0;
          for(auto j=(*i).begin();j!=(*i).end();j++){
              max+=*j;
          }
          if(max>ans)
          {
              ans=max;
          }
      } 
      return ans;
    }
};

//题解
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = INT_MIN;
        for (auto &account : accounts) {
            maxWealth = max(maxWealth, accumulate(account.begin(), account.end(), 0));
        }
        return maxWealth;
    }
};
