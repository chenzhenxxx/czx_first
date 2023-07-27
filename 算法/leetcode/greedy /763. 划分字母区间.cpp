class Solution {
public:
    vector<int> partitionLabels(string s) {
       vector<int> ans;
       int hash[27]={0};
       for(int i=0;i<s.size();i++)
       hash[s[i]-'a'] = i;
       int right = 0;
       int left = 0;
       for(int i=0;i<s.size();i++)
       {
           right = max(right,hash[s[i]-'a']);
           if(i == right)
           {
               ans.push_back(right-left+1);
               left = i+1;
               //right =right +1; 不用这一句，在新的开始的元素的最远下标最起码为i+1,不然会在前面出现过
           }
       }
       return ans;
    }
};