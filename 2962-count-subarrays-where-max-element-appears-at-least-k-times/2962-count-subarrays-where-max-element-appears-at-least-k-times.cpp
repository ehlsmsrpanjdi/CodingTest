class Solution {
public:
	long long countSubarrays(vector<int>& nums, int k) {
		int n = nums.size();
		int freq = 0;
		int maxvalue = *std::max_element(nums.begin(), nums.end());
		long long count = 0;
		int left = 0;
		for (int right = 0; right < n; ++right) {
			if (nums[right] == maxvalue) {
				freq++;
			}

			while (freq >= k) {
				count += n - right;

				if (nums[left] == maxvalue) {
					freq--;
				}
				++left;
			}
		}


		return count;
	}
};