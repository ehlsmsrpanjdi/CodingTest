
class Solution {
public:
	bool isValid(string s) {

		stack<char> st;

		for (char ch : s) {
			if (st.empty() == true) {
				st.push(ch);
			}
			else {

				while (!st.empty()) {
					char c = st.top();
					if (ch == ']') {
						if (c != '[') {
							return false;
						}
						st.pop();
						break;
					}
					else if (ch == '}') {
						if (c != '{') {
							return false;
						}
						st.pop();
						break;
					}
					else if (ch == ')') {
						if (c != '(') {
							return false;
						}
						st.pop();
						break;
					}
					else {
						st.push(ch);
						break;
					}
				}
			}
		}
		if (st.size() != 0) {
			return false;
		}
		else {
			return true;
		}
	}
};
