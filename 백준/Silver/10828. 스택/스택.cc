#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	std::stack<int> st;

	int Count = 0;
	int num = 0;
	std::cin >> Count;
	std::string str;


	while (Count--) {
		std::cin >> str;
		if (str == "push") {
			std::cin >> num;
			st.push(num);
		}
		else if (str == "top") {
			if (st.empty() != true) {
				std::cout << st.top() << '\n';
			}
			else {
				std::cout << -1 << '\n';
			}
		}
		else if (str == "pop") {
			if (st.empty() != true) {
				std::cout << st.top() << '\n';
				st.pop();
			}
			else {
				std::cout << -1 << '\n';
			}
		}
		else if (str == "size") {
			std::cout << st.size() << '\n';
		}
		else if (str == "empty") {
			if (st.empty() != true) {
				std::cout << 0 << '\n';
			}
			else {
				std::cout << 1 << '\n';
			}
		}
	}

}