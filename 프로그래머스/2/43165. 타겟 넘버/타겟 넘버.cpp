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

void dfs(vector<int>& vec, int val, int index, int target, int& answer) {
	if (vec.size() - 1 == index) {
		if (val == target) {
			++answer;
		}
		return;
	}
	dfs(vec, val + vec[index + 1], index + 1, target, answer);
	dfs(vec, val - vec[index + 1], index + 1, target, answer);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	dfs(numbers, numbers[0], 0, target, answer);
	dfs(numbers, -numbers[0], 0, target, answer);

	return answer;
}
