#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(std::vector<int>& _Time, int n, long long mid) {

	long long total = 0;
	for (int i : _Time) {
		total += (long long)(mid / i);
		if (total >= n) {
			return true;
		}
	}
	return false;
}


long long solution(int n, vector<int> times) {
	long long answer = 0;

	std::sort(times.begin(), times.end());

	long long left = 1;
	long long right = (long long)times.back() * n;

	while (left <= right) {
		long long mid = left + (right - left) / 2;
		if (isPossible(times, n, mid) == true) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return left;
}

