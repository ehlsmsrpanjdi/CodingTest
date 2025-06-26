class MinStack {
public:
    stack<int> minst;
    stack<int> st;

    MinStack() {

    }

    void push(int val) {
		st.push(val);

		if (minst.empty() || minst.top() >= val) {
			minst.push(val);
		}
    }

	void pop() {
		if (st.empty()) {
			return;
		}
		if (st.top() == minst.top()) {
			minst.pop();
		}
        st.pop();
    }

    int top() {
		if (st.empty()) {
			return -1; // or throw an exception
		}
        return st.top();
    }

    int getMin() {
		if (minst.empty()) {
			return st.top();
		}
		return minst.top();
    }
};
