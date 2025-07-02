std::vector<std::vector<int>> answer;

int VecSize;
int TargetValue;

void BackTracking(std::vector<int>& vec, std::vector<int>& nums, int TotalValue, int Start) {

	if (TotalValue > TargetValue) {
		return;
	}
	else if (TotalValue == TargetValue) {
		answer.push_back(vec);
	}

	for (int i = Start; i < VecSize; ++i) {
		vec.push_back(nums[i]);
		TotalValue += nums[i];
		BackTracking(vec, nums, TotalValue, i);
		vec.pop_back();
		TotalValue -= nums[i];
	}

}


class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

		TargetValue = target;
		VecSize = candidates.size();
		answer.clear();
		std::vector<int> vec;
		BackTracking(vec, candidates, 0, 0);

		return answer;
	}
};
