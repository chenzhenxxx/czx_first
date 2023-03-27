   //辅助最小栈法
// class MinStack {
// public:
//     /** initialize your data structure here. */
//     stack<int> smin;
//     stack<int> st;
//     MinStack() {
//        while(!smin.empty()){
//            smin.pop();
//        }

//        while(!st.empty()){
//            st.pop();
//        }

//     }
    
//     void push(int x) {
      
//       st.push(x);
//       int minval;
//       if(smin.empty())
//       {
//           minval=x;
//       }
//       else{
//       minval = std::min(smin.top(),x);
//       }
//       smin.push(minval);
//     }
    
//     void pop() {
     
//      smin.pop();
//      st.pop();
//     }
    
//     int top() {

//       return st.top();     

//     }
    
//     int min() {
//         return smin.top();
//     }
// };


//
