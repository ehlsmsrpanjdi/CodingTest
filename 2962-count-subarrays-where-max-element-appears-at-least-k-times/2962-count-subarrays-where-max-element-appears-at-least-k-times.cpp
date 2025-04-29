class Solution {
public:
	long long countSubarrays(vector<int>& nums, int k) {
		int left = 0;
		int right = 0;

		int n = nums.size();

		int maxValue = *std::max_element(nums.begin(), nums.end());

		int frequency = 0;

		long long count = 0;

		for (; right < n; right++)
		{
			if (nums[right] == maxValue) {
				frequency++;
			}

			while (frequency >= k) {
				count += n - right;
				if (nums[left] == maxValue) {
					frequency--;
				}
				++left;
			}
		}

		return count;

	}
};