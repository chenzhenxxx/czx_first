class Solution {
public:
    string countAndSay(int n) {
       if(n==1)
       return "1";
       string s="11";
       int ans=2;
       while(ans<n)
       {
           string tmp;
           int cnt=1;
           for(int i=1;i<s.size();i++)
           {  
               if(s[i]!=s[i-1])
               {
                   tmp.push_back(cnt+'0');
                   tmp.push_back(s[i-1]);
                   cnt=1;
               }
               else
               cnt++;
           }
           tmp.push_back(cnt+'0');
           tmp.push_back(s[s.size()-1]);
           ans++;
           s=tmp;
       }
       return s;
    }
};