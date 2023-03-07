class MyQueue {
public:
    
    /*
    
        we will have two stacks 1. input stack to maintain the input and 2. output stack to give output
        if we use observe the previous implementations we are pushing elements into second stack everytime
        a element is coming which is not required as the pushed element are in format of queue.
        and we will need the elements of first stack only when the second stack is empty as all the elements in second
        stack were pushed first.
        
        so the operations inlude 
        1. push(x) -> O(1)
            -> add x to input element
        
        2. pop() -> O(1) amortized
            -> if (output is not emepty)
                ouput.pop()
            -> else input stack -> output stack
                output.pop
                
        3. top() O(1) amortized
            -> if (output is not empty)
                output.top()
            -> else input stack -> output stack
                output.top()
    
        SC -> O(2*n)
    
    */
    
    stack<int> input,output;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty())
        {
            int val=output.top();
            output.pop();
            return val;
        }
        else
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            int val=output.top();
            output.pop();
            return val;
        }
    }
    
    int peek() {
        if(!output.empty())
        {
            return output.top();
        }
        else
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};