class MinStack {
private:
    stack<int> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        int minimum = st.top();
        stack<int> temp;

        while (st.size()) {
            minimum = min(minimum, st.top());
            temp.push(st.top());
            st.pop();
        }

        while (temp.size()) {
            st.push(temp.top());
            temp.pop();
        }

        return minimum;
    }
};
