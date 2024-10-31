#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	std::stack<int> st;
	std::vector<char> vec;
	std::set<int> se;
	int Count = 0;
	cin >> Count;
	int num = 0;
	int temp = 0;
	while (Count--) {
		cin >> num;
		if (num > temp) {
			while (num > temp) {
				if (se.find(++temp) != se.end()) {
					continue;
				}
				st.push(temp);
				vec.push_back('+');
				se.insert(temp);
			}
			vec.push_back('-');
			st.pop();
			continue;
		}
		else {
			while (num < temp) {
				if (st.top() != num) {
					std::cout << "NO";
					return 0;
				}
				else {
					temp = num;
					vec.push_back('-');
					st.pop();
				}
			}
		}

	}
	for (char c : vec) {
		std::cout << c << '\n';
	}
}