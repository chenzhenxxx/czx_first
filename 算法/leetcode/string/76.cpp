class Solution {
public:
    unordered_map<char,int> mps,mpt;
    bool check()
    {
        for(auto &i:mpt)
        {
            if(mps[i.first]<i.second)return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        
        for(auto &i:t)
        mpt[i]++;

        int l=0,r=-1;
        int len=INT_MAX;
        int ans_L=-1;

        while(r<int(s.size()))
        {   
            if(mpt.find(s[++r])!=mpt.end())
            {
                mps[s[r]]++;
            }
            while(check()&&l<=r)
            {
                if(r-l+1<len)
                {
                    len=r-l+1;
                    ans_L=l;
                }
                if(mpt.find(s[l])!=mpt.end())
                {
                    mps[s[l]]--;
                }
                l++;
            }
            
        }

        return ans_L==-1 ?string():s.substr(ans_L,len);
    }
};