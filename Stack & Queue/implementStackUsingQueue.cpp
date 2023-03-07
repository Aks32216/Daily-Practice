class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    queue<int> q;
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        int n=q.size();
        for(int i=1;i<n;++i)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x=q.front();
        q.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.size()==0?true:false;
    }
};