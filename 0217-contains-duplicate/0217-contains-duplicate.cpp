class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> unMap;
		for (int val : nums) {
			++unMap[val];
			if (unMap[val] >= 2) {
				return true;
			}
		}
		return false;
	}
};
