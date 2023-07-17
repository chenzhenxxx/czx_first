class MyQueue {
public:
    stack<int> in;
    stack<int> out;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!out.empty()){
            in.push(out.top());
            out.pop();
        }
        in.push(x);
    }
    
    int pop() {
       while(!in.empty()){
           out.push(in.top());
           in.pop();
       }
       int x = out.top();
       out.pop();
       return x;
    }
    
    int peek() {
      while(!in.empty()){
           out.push(in.top());
           in.pop();
       }
       int x = out.top();
       return x;
    }
    
    bool empty() {
       if(in.empty()&&out.empty())
       return true;
       else
       return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */