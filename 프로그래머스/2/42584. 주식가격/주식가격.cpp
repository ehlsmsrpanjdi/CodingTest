#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	std::stack<pair<int, int>> qu;
	std::pair<int, int> pa;

	int priceSize = prices.size();

	answer.resize(priceSize);

	for (int i = 0; i < priceSize; ++i) {
		if (qu.empty()) {
			qu.push(make_pair(prices[i], i));
		}
		else {
			while (!qu.empty() && qu.top().first > prices[i]) {
				pa = qu.top();
				answer[pa.second] = i - pa.second;
				qu.pop();
			}
			qu.push(make_pair(prices[i], i));
		}
	}

	while (!qu.empty()) {
		pa = qu.top();
		qu.pop();
		answer[pa.second] = priceSize - pa.second - 1;
	}

	return answer;
}