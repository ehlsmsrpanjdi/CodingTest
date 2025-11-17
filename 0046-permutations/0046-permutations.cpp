using namespace std;

void Tracking(vector<int>& nums, std::vector<int>& vec, std::vector<bool>& visited, vector<vector<int>>& answer) {

	if (vec.size() == nums.size()) {
		answer.push_back(vec);
		return;
	}

	for (int i = 0; i < nums.size(); ++i) {
		if (visited[i] == false) {
			visited[i] = true;
			vec.push_back(nums[i]);
			Tracking(nums, vec, visited, answer);
			vec.pop_back();
			visited[i] = false;
		}
	}


}

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {

		vector<vector<int>> answer;

		std::vector<bool> isvisited = std::vector<bool>(nums.size(), false);
		for (int i = 0; i < nums.size(); ++i) {
			std::vector<int> vec;
			vec.push_back(nums[i]);
			isvisited[i] = true;
			Tracking(nums, vec, isvisited, answer);
			vec.pop_back();
			isvisited[i] = false;
		}
return answer;
	}
};

