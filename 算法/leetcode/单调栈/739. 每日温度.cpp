class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> ans(temperatures.size(),0);
        s.push(0);
        int cnt=0;
        int index=0;
        for(int i=1;i<temperatures.size();i++)
        {
            
            
            while(!s.empty()&&temperatures[i]>temperatures[s.top()])
            {  
                ans[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
          

        }
        return ans;
    }
};