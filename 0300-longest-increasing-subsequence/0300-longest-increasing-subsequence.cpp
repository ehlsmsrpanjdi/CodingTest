class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		std::vector<int> vec;
		std::vector<int>::iterator iter;
		int length = 0;
		for (int i = 0; i < nums.size(); ++i) {

			iter = std::lower_bound(vec.begin(), vec.end(), nums[i]);

			if (iter == vec.end()) {
				vec.push_back(nums[i]);
			}
			else {
				length = iter - vec.begin();

				vec[length] = nums[i];
			}


		}
		return vec.size();
	}
};
