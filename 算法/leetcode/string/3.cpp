class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_set<char> st;
      int right=-1;
      int ans=0;
      for(int left=0;left<s.size();left++)
      {
          if(left!=0)
          {
              st.erase(s[left-1]);
          }
          while(right+1<s.size()&&!st.count(s[right+1]))
          {
              st.insert(s[right+1]);
              right++;
          }
        ans=max(ans,right-left+1);
      }
      return ans;
    }
};