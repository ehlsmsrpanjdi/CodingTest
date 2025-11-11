class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		std::unordered_map<int, int> unMap;

		std::unordered_map<int, int>::iterator iter;

		std::vector<int> vec;

		for (int i = 0; i < nums.size(); ++i) {

			iter = unMap.find(nums[i]);
			if (unMap.end() != iter && (*iter).second != i) {
				vec.push_back((*iter).second);
				vec.push_back(i);
				return vec;
			}

			unMap[target - nums[i]] = i;
		}
		return vec;
	}
};