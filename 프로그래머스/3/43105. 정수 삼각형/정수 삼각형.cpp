#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <stack>
#include <iostream>


using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;

	vector<vector<int>> dp(triangle.size());
	for (int i = 0; i < triangle.size(); i++) {
		dp[i].resize(i + 1);
	}

	dp[0][0] = triangle[0][0];


	for (int i = 1; i < triangle.size(); ++i) {
		for (int j = 0; j < i + 1; ++j) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
			}
		}
	}



	return *max_element(dp[triangle.size() - 1].begin(), dp[triangle.size()  - 1].end());
}
