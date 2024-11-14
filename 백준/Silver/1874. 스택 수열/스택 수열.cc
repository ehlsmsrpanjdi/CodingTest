#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int index, num;
	cin >> index;
	int value = 0;
	std::stack<int> st;
	std::set<int> se;
	std::vector<char> vec;
	while (index--) {
		cin >> num;
		while (value < num) {
			if (se.find(value + 1) == se.end()) {
				st.push(++value);
				se.insert(value);
				vec.push_back('+');
			}
			else {
				++value;
			}
		}
		while (value >= num) {
			if (st.top() != num) {
				std::cout << "NO";
				return 0;
			}
			else {
				st.pop();
				vec.push_back('-');
				value = num - 1;
			}
		}

	}

	for (char c : vec) {
		std::cout << c << '\n';
	}

	return 0;
}