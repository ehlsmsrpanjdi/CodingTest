#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



bool isPositive(std::vector<int>& _times, long long _midValue, int _people) {

	long long count = 0;

	for (int t : _times) {
		count += (long long)_midValue / t;
		if (count >= _people) return true; // 조기 종료
	}

	return false;

}


long long solution(int n, vector<int> times) {
	long long answer = 0;

	std::sort(times.begin(), times.end());

	long long left = 1;  // 최소
	long long right = (long long)times.back() * n;  // 최대

	while (left <= right) {
		long long mid = left + (right - left) / 2;

		if (isPositive(times, mid, n) == true) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return left;
}