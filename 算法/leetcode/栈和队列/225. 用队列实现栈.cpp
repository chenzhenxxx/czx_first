class MyStack {
public:
    queue<int> que;
    MyStack() {

    }
    
    void push(int x) {
       que.push(x);
    }
    
    int pop() {
        int size = que.size()-1;
        while(size--){
            int x= que.front();
            que.pop();
            que.push(x);
        }
        int ans = que.front();
        que.pop();
        return ans;
    }
    
    int top() {
      return que.back();
    }
    
    bool empty() {
        if(!que.empty()) return false;
        return true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */