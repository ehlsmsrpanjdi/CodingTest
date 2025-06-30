#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <iostream>

using namespace std;


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int MinValue = INT_MAX;
		int MaxValue = -1;
		int answer = 0;

		for (int i = 0; i < prices.size(); ++i) {
			if (MinValue > prices[i]) {
				MinValue = prices[i];
			}
			answer = std::max(answer, prices[i] - MinValue);
		}

		return answer;
	}
};

