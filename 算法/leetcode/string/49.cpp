class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>> mp;
       for(auto &i:strs)
       {   string str=i;
           sort(str.begin(),str.end());
           mp[str].emplace_back(i);
       }

       vector<vector<string>> ans;
       for(auto i=mp.begin();i!=mp.end();i++)
       ans.emplace_back(i->second);
       return ans;
    }
};