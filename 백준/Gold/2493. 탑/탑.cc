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
	std::stack<std::pair<int, int>> st;
	std::vector<int> vec;
	std::pair<int, int> pa;
	st.push(make_pair(100000001, value));
	while (index--) {
		++value;
		cin >> num;
		pa = st.top();
		while (pa.first < num) {
			st.pop();
			pa = st.top();
		}
		vec.push_back(pa.second);
		st.push(make_pair(num, value));
	}

	for (int i : vec) {
		std::cout << i << '\n';
	}

	return 0;
}