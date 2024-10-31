#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	std::stack<int> st;

	int Count = 0;
	cin >> Count;
	int num = 0;
	while (Count--) {
		cin >> num;
		if (num == 0 && !st.empty()) {
			st.pop();
			continue;
		}
		st.push(num);
	}
	while (!st.empty()) {
		Count += st.top();
		st.pop();
	}
	std::cout << Count + 1;
}