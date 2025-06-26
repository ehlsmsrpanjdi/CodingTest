class MyStack {
public:
    stack<int> st;

    MyStack() {

    }

    void push(int x) {
		st.push(x);
    }

    int pop() {
		int value =st.top();
		st.pop();
		return value;
    }

    int top() {
		return st.top();
    }

    bool empty() {
		return st.empty();
    }
};
