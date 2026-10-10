class MinStack {
public:
    stack<long long> st;long long mini;
    MinStack() {
        
    }
    
    void push(int val) {
        long long value = val;
        if(st.empty()){
            st.push(value);
            mini = value;
        }
        else {
            if(value >= mini){
                st.push(value);
            }
            else {
                st.push(2LL*value-mini);
                mini = value;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top() >= mini){
            st.pop();return;
        }
        mini = 2LL*mini-st.top();
        st.pop();
    }
    
    long long top() {
        if(st.empty()) return -1;
        if(st.top()>=mini)return st.top();
        else return mini;
    }
    
    long long getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * long long param_3 = obj->top();
 * long long param_4 = obj->getMin();
 */