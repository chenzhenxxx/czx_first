class Solution {
public:
    int evalRPN(vector<string>& tokens) {
     stack<long long> st;
     int size = tokens.size();
     for(int i=0;i<size;i++){
         if(!st.empty()&&tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
         {
             long long num1 = st.top();
             st.pop();
             long long num2 = st.top();
             st.pop();
             if (tokens[i] == "+") st.push(num2 + num1);
                if (tokens[i] == "-") st.push(num2 - num1);
                if (tokens[i] == "*") st.push(num2 * num1);
                if (tokens[i] == "/") st.push(num2 / num1);
                
         }
         else
         {
             st.push(stoll(tokens[i]));
         }
     }
     return st.top();
    }
};