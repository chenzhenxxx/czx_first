class Solution {
public:
    vector<string> result;
    void backtracking(string s, int start,int times,string path)
    {     if(times>3) return;
          if(times==3)
          {  if(!judge(s,start,s.size()-1))
              return;
              string str = s.substr(start,s.size()-start);
              str="."+str;
              path+=str;
              result.push_back(path);
              return;
          }
          for(int i=start;i<s.size()-1;i++)
          {
              if(judge(s,start,i))
              {   string str="";
                  if(path.size()>0)
                  {
                      str+=".";
                  }
                  str+=s.substr(start,i-start+1);
                
                  backtracking(s,i+1,times+1,path+str);
                  
              }
          }
    }

    bool judge(string s ,int begin,int end)
    {
        if(end-begin>=1&&s[begin]=='0') return false;
        string str = s.substr(begin,end-begin+1);
        const char * p = str.c_str();
        long long x = atoll(p);
        if(x>255) return false;

        return true;
        
    }
    vector<string> restoreIpAddresses(string s) {
       backtracking(s,0,0,"");
       return result;
    }
};