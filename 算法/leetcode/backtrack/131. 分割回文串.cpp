class Solution {
public:
    vector<string> path;
    vector<vector<string>> result;
    void backtracking (const string& s, int startIndex)
    {
         if(startIndex>=s.size()) 
         {   result.push_back(path);
             return;
         }

         for(int i=startIndex;i<s.size();i++)
         {
             if(judge_hw(s,startIndex,i))
             {
                 string str = s.substr(startIndex,i-startIndex+1);
                 path.push_back(str);
                 backtracking(s,i+1);
                 path.pop_back();

             }
         }
    }

    bool judge_hw(string s,int begin,int end)
    {
        for(int i=begin,j=end;i<j;i++,j--)
        {
            if(s[i]!=s[j]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
          backtracking(s,0);
          return result;
    }
};