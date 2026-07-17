class MinStack {
private:
    stack<int> st;
    stack<int> min_st;
    int size = 0;
public:
    
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        if(size == 0) min_st.push(val);
        else min_st.push(min(val, min_st.top()));
        size++;
    }
    
    void pop() {
        st.pop();
        min_st.pop();
        size--;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
