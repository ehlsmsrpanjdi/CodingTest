#include <string>
#include <vector>

using namespace std;

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

vector<int> solution(int n) {
	vector<int> answer;

	std::vector<std::vector<int>> vec(n);

	for (int i = 0; i < n; ++i) {
		vec[i].resize(i + 1);
	}

	int count = 0;

	int total = 0;

	for (int i = 1; i <= n; ++i) {
		total += i;
	}

	int val = n;

	int xval = 0;
	int yval = 0;

	while (count < total) {

		for (int i = 0; i < val; ++i) {
			vec[xval++][yval] = ++count;
		}

		--val;

		--xval;
		++yval;

		for (int i = 0; i < val; ++i) {
			vec[xval][yval++] = ++count;
		}

		--val;
		--yval;
		--xval;
		--yval;

		for (int i = 0; i < val; ++i) {
			vec[xval--][yval--] = ++count;
		}
		--val;
		++yval;
		++xval;
		++xval;
	}

	for (auto& elementVec : vec) {
		for (auto val : elementVec) {
			answer.push_back(val);
		}
	}


	return answer;
}
