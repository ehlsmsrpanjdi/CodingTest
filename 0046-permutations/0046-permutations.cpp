void Tracking(std::vector<int>& current, std::vector<bool> isvisit, std::vector<int>& nums, std::vector<std::vector<int>>& answer) {

	if (current.size() == nums.size()) {
		answer.push_back(current);
	}

	for (int i = 0; i < nums.size(); ++i) {
		if (isvisit[i] == false) {
			current.push_back(nums[i]);
			isvisit[i] = true;
			Tracking(current, isvisit, nums, answer);
			isvisit[i] = false;
			current.pop_back();
		}
	}
}


class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		std::vector<int> vec;
		std::vector<bool> visited = vector<bool>(nums.size(), false);
		vector<vector<int>> answer;

			Tracking(vec, visited, nums, answer);

        return answer;
	}
};