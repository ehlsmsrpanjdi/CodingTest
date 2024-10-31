#include <string>
#include <vector>
#include <stack>
#include <iostream>
int main() {
	int Count = 0;
	int num = 0;
	int index = 0;
	std::stack<std::pair<int, int>> st;
	st.push(std::make_pair(100000001, 0));
	std::vector<int> vec;
	std::cin >> Count;
	while (Count--) {
		std::cin >> num;
		while (st.top().first < num) {
			st.pop();
		}
		vec.push_back(st.top().second);
		st.push(std::make_pair(num, ++index));
	}
	for (int i : vec) {
		std::cout << i << ' ';
	}
}