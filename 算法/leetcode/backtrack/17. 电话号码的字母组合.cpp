class Solution {
public:
    const string letterMap[10] = {
            "", // 0
            "", // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs", // 7
            "tuv", // 8
            "wxyz", // 9
        };
        string path;
        vector<string> ans;
        void deal(string digits,int index)
        {   
            if(index==digits.size())
            {
                ans.push_back(path);
                return;
            }
                for(int j=0;j<letterMap[digits[index]-'0'].size();j++)
                {
                      path.push_back(letterMap[digits[index]-'0'][j]);
                      deal(digits,index+1);
                      path.pop_back();
                }
        }
        vector<string> letterCombinations(string digits) {
         if (digits.size() == 0) {
            return ans;
        }
         deal(digits,0);
         return ans;
    }
};