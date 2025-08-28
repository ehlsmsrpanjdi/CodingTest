#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
	int answer = *max_element(diffs.begin(), diffs.end());
	long long low = 1;
	long long high = *max_element(diffs.begin(), diffs.end());
	long long mid = (high + low) / 2;
	long long total;
	int prev;
	while (low <= high) {
		mid = (high + low) / 2;
		total = 0;
		prev = 0;
		for (int i = 0; i < diffs.size(); ++i) {
			if (diffs[i] <= mid) {
				total += times[i];
			}
			else {
				long long minus = diffs[i] - mid;
				total += ((prev + times[i]) * minus);
				total += times[i];
			}
			prev = times[i];
		}
		if (total <= limit) {
			if (answer > mid) {
				answer = mid;
			}
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return answer;
}
