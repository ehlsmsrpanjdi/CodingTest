#include <iostream>
#include <string>
#include <regex>
#include <queue>
#include <stack>
using namespace std;

int bfs(vector<int>& numbers, int target) {
	int numsize = numbers.size();
	std::queue<std::pair<int, int>> qu;
	qu.push(make_pair(numbers[0], 0));
	qu.push(make_pair(-numbers[0], 0));
	std::pair<int, int> pqu;
	int iqu = 0;
	while (!qu.empty()) {
		pqu = qu.front();
		qu.pop();
		if (pqu.second + 1 < numsize) {
			qu.push(make_pair(pqu.first + numbers[pqu.second + 1], pqu.second + 1));
			qu.push(make_pair(pqu.first - numbers[pqu.second + 1], pqu.second + 1));
		}
		else {
			if (target == pqu.first) {
				++iqu;
			}
		}
	}
	return iqu;
}

int dfs(vector<int>& numbers, int target) {
	int numsize = numbers.size();
	std::stack<std::pair<int, int>> st;
	st.push(make_pair(numbers[0], 0));
	st.push(make_pair(-numbers[0], 0));
	std::pair<int, int> pst;
	int ist = 0;
	while (!st.empty()) {
		pst = st.top();
		st.pop();
		if (pst.second + 1 < numsize) {
			st.push(make_pair(pst.first + numbers[pst.second + 1], pst.second + 1));
			st.push(make_pair(pst.first - numbers[pst.second + 1], pst.second + 1));
		}
		else {
			if (target == pst.first) {
				++ist;
			}
		}
	}
	return ist;
}


int solution(vector<int> numbers, int target) {

	return bfs(numbers, target);
}
