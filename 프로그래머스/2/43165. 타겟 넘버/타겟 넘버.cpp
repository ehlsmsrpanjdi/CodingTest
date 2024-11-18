#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;



int solution(vector<int> numbers, int target) {

	int result = 0;
	std::pair<int, int> pa;
	int numsize = numbers.size();
	std::queue<std::pair<int, int>> qu;
	int n = 0;
	//지금 총합, 지금 몇 번째까지 더했냐
	qu.push(std::make_pair(n, numbers[n]));
	qu.push(std::make_pair(n, -numbers[n]));

	while (!qu.empty()) {
		pa = qu.front();
		qu.pop();
		n = pa.first;
		if (n == numsize - 1) {
			if (pa.second == target) {
				++result;
			}
			continue;
		}
		qu.push(std::make_pair(n + 1, pa.second + numbers[n + 1]));  // 1, 1  (1  -1)
		qu.push(std::make_pair(n + 1, pa.second - numbers[n + 1]));
		// 1 1  1 -1  -1 1   -1 -1  2 0 0 -2
	}

	return result;
}

