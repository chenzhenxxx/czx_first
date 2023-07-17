class Solution {
public:
    bool isValid(string s) {
     stack<char> st;
     map<char,char> judge;
     judge[')']='(';
     judge['}']='{';
     judge[']']='[';
     st.push(s[0]);
     for(int i=1;i<s.size();i++){
         if(!st.empty()&&judge[s[i]]==st.top())
         {
             st.pop();
         }
         else st.push(s[i]);
     }
     if(!st.empty())return false;
     else return true;
    }
};