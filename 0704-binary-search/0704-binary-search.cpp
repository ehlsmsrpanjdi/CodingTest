class Solution {
public:
	int search(vector<int>& nums, int target) {

		int left = 0;
		int right = nums.size();

		int mid = (left + right) / 2;

		bool isFind = false;

		while (left <= right) {

			if (mid >= nums.size()) {
				break;
			}

			if (target == nums[mid]) {
				return mid;
			}

			else if (nums[mid] < target) {
				left = mid + 1;
			}

			else {
				right = mid - 1;
			}

			mid = (left + right) / 2;
		}
		return -1;
	}
};
