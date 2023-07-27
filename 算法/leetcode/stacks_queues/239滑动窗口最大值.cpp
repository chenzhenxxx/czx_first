class Solution {
public:
      class Myqueue{
          public:
          deque<int> dq;
          void pop(int x){
            if(!dq.empty()&&x==dq.front()){
                dq.pop_front();
            }
          }

          void push(int x){
                 while(!dq.empty()&&x>dq.back()){
                     dq.pop_back();
                   }
                   dq.push_back(x);
          }

          int front(){
              return dq.front();
          }
      };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
           Myqueue qe;
           vector<int> ans;
           for(int i=0;i<k;i++)
           {
               qe.push(nums[i]);
           }
           ans.push_back(qe.front());

           for(int i=k;i<nums.size();i++){
               qe.push(nums[i]);
               qe.pop(nums[i-k]);
               ans.push_back(qe.front());
           }
           return ans;


    }
};