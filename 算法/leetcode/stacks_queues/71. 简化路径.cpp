class Solution {
public:
    string simplifyPath(string path) {
        deque<string> due;
        int i=0;
        while(i<path.size()){
            if(i<path.size()&&path[i]=='/')i++;
            else{
                string tmp;
                while(i<path.size()&&path[i]!='/')tmp+=path[i++];
                if(tmp==".."&&!due.empty()) due.pop_back();
                else if(tmp!=".."&&tmp!=".") due.push_back(tmp);
            }
        }
        string ans="/";
        while(!due.empty())
        {ans+=due.front()+"/";
        due.pop_front();
        }
        if(ans.size()>1) ans.pop_back();
        return ans;
    }
};