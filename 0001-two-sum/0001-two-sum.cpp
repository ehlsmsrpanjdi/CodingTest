class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {  //2, 7
		std::unordered_map<int, int> map;
		std::vector<int> list;
		for (int i = 0; i < nums.size(); ++i) {
			int com = target - nums[i];
			if (map.contains(com) == true) {
				list = { map[com], i };
				return list;
			}
			map[nums[i]] = i;
		}

		return list;
	}
};