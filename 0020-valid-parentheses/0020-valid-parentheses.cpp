class Solution {
public:
	bool isValid(string s) {
		std::stack<char> st;


		for (char c : s) {
			if (st.empty()) {
				st.push(c);
				continue;
			}

			if (c == '(' || c == '[' || c == '{') {
				st.push(c);
				continue;
			}

			if (st.top() == '(' && c == ')') {
				st.pop();
				continue;
			}
			
			if (st.top() == '[' && c == ']') {
				st.pop();
				continue;
			}

			if (st.top() == '{' && c == '}') {
				st.pop();
				continue;
			}

			else {
				return false;
			}
			st.push(c);
		}
		if (st.empty()) {
			return true;
		}
		else {
			return false;
		}
	}
};