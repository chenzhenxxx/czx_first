class Solution {
public:
    map<string,map<string,int>> target;
    bool backtracking(int ticketnum,vector<string>& result)
    {
        if(result.size()==ticketnum+1)
        {
            return true;
        }

        for(pair<const string,int>& targets: target[result[result.size()-1]])
        {
            if(targets.second>0)
            {
                targets.second--;
                result.push_back(targets.first);
                if(backtracking(ticketnum,result)) return true;
                targets.second++;
                result.pop_back();
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
          vector<string> result;

          for(const vector<string>&vec:tickets)
          {
              target[vec[0]][vec[1]]++;
          }
          result.push_back("JFK");
          backtracking(tickets.size(),result);

          return result;
    }
};