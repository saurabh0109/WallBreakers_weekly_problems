class MyStack {
public:
    /** Initialize your data structure here. */
  
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
      int x ;
      while(!q1.empty())
      {
         x = q1.front();
         if(q1.size() > 1) 
            q2.push(x);
         q1.pop();
      }
      
      q1 = q2;
      while(!q2.empty()) q2.pop();
      
      return x;
      
    }
    
    /** Get the top element. */
    int top() {
      int x ;
      while(!q1.empty())
      {
         x = q1.front();
         q2.push(x);
         q1.pop();
      }
      
      q1 = q2;
      while(!q2.empty()) q2.pop();
      
      return x;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
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