std::vector<std::vector<int>> answer;
int targetValue = 0;

void BackTracking(std::vector<int>& current, const std::vector<int>& origin, int _total, int _Start) {

	if (_total > targetValue) {
		return;
	}

	if (_total == targetValue) {
		answer.push_back(current);
	}

	for (int i = _Start; i < origin.size(); ++i) {
		current.push_back(origin[i]);
		_total += origin[i];
		BackTracking(current, origin, _total, i);
		_total -= origin[i];
		current.pop_back();
	}
}

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		targetValue = target;
		std::vector<int> vec;
		answer.clear();
		BackTracking(vec, candidates, 0, 0);
		return answer;
	}
};