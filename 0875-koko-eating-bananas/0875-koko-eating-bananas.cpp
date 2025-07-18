bool IsPossible(std::vector<int>& piles, int h, int mid) {
	int total = 0;
	for (int i : piles) {
		if (i % mid == 0) {
			total += i / mid;
		}
		else {
			total += i / mid + 1;
		}
		if (total > h) {
			return false;
		}
	}

	return true;
}

class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int h) {
		std::sort(piles.begin(), piles.end());

		int left = 1;
		int right = piles.back();

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
