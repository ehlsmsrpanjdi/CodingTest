bool IsPossible(std::vector<int>& piles, int h, int mid) {
	int total = 0;
	for (int i : piles) {
		total += (i + mid - 1) / mid;
		if (total > h) {
			return false;
		}
	}
	return true;
}

class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int h) {

		int left = 1;

		int right = *std::max_element(piles.begin(), piles.end());


		while (left <= right) {
			int mid = left + (right - left) / 2;

			if (IsPossible(piles, h, mid) == true) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}

		return left;

	}
};