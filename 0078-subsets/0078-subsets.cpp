std::vector<std::vector<int>> answer;

int VecSize;

void BackTracking(std::vector<int>& vec, std::vector<int>& nums, int _Start) {
	answer.push_back(vec);
	for (int i = _Start; i < VecSize; ++i) {
		vec.push_back(nums[i]);
		BackTracking(vec, nums, i + 1);
		vec.pop_back();
	}

}


class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		VecSize = nums.size();
		answer.clear();
		std::vector<int> vec;
		BackTracking(vec, nums, 0);

		return answer;
	}
};

