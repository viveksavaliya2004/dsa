class MinStack {
public:
    stack<int> s;
    stack<int> ss;

    MinStack() {
    }
    
    void push(int val) {
        s.push(val);

        if (ss.empty() || ss.top() >= val) {
            ss.push(val);
        }
    }
    
    void pop() {
        if (s.empty()) {
            return;
        }

        int ans = s.top();   // get value first
        s.pop();             // then pop

        if (!ss.empty() && ans == ss.top()) {
            ss.pop();
        }
    }
    
    int top() {
        if (s.empty()) {
            return -1;
        }
        return s.top();
    }
    
    int getMin() {
        if (ss.empty()) {
            return -1;
        }
        return ss.top();
    }
};