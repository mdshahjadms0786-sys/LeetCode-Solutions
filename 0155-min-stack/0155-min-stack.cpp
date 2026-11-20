
class MinStack {
    stack<int> st;
    stack<int> mini;

public:
    MinStack() {
        
    }

    void push(int val) {
        st.push(val);

        if (mini.empty() || val <= mini.top()) {
            mini.push(val);
        }
    }

    void pop() {
        if (st.top() == mini.top()) {
            mini.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return mini.top();
    }
};
