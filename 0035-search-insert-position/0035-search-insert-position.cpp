class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int value =  std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return value;
    }
};