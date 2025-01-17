#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <unordered_map>
#include <deque>
#include <set>
#include <queue>
using namespace std;

struct Compare {
	bool operator()(int a, int b) {
		int _a = std::abs(a);
		int _b = std::abs(b);
		if (_a == _b) {
			return a > b;
		}
		return _a > _b;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<int, std::vector<int>, Compare> qu;
	int n, m;
	std::cin >> n;
	std::vector<int> vec;

	while (n--) {
		std::cin >> m;
		if (m == 0) {
			if (qu.empty()) {
				std::cout << "0\n";
				vec.push_back(0);
			}
			else {
				std::cout << qu.top() << '\n';
				vec.push_back(qu.top());
				qu.pop();
			}
		}
		else {
			qu.push(m);
		}
	}
	return 0;
}