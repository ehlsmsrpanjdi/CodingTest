
bool IsPossible(std::vector<int>& weights, int days, int mid) {
	int totalWeight = 0;
	int totalDays = 0;
	for (int i : weights) {
		if (i > mid) {
			return false;
		}
		if (totalWeight + i <= mid) {
			totalWeight += i;
		}
		else {
			totalWeight = i;
			++totalDays;
			if (totalDays > days) {
				return false;
			}
		}
	}
	if (totalWeight > 0) {
		++totalDays;
		if (totalDays > days) {
			return false;
		}
	}
	return true;
}
class Solution {
public:
	int shipWithinDays(vector<int>& weights, int days) {
		int left = 1;
		int right = 0;
		for (int i : weights) {
			right += i;
		}



		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (true == IsPossible(weights, days, mid)) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return left;

	}
};
