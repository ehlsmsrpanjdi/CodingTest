std::vector<std::vector<int>> answer;
std::vector<bool> isVisited;

void BackTracking(std::vector<int>& current, const std::vector<int>& origin) {
	if (current.size() == origin.size()) {
		answer.push_back(current);
	}

	for (int i = 0; i < origin.size(); ++i) {
		if (isVisited[i] == false) {
		current.push_back(origin[i]);
		isVisited[i] = true;
		BackTracking(current, origin);
		isVisited[i] = false;
		current.pop_back();
		}
	}
}

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		std::vector<int> vec;
		isVisited.resize(nums.size(), false);
		answer.clear();
		BackTracking(vec, nums);
		return answer;
	}
};