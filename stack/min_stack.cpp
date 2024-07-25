class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (istack.empty()) {
            istack.push(val);
            mstack.push(val);
            return;
        }

        int minval = min(mstack.top(), val);
        istack.push(val);
        mstack.push(minval);
    }
    
    void pop() {
        istack.pop();
        mstack.pop();
    }
    
    int top() {
        return istack.top();
    }
    
    int getMin() {
        return mstack.top();
    }

private:
    stack<int> istack;
    stack<int> mstack;
};
