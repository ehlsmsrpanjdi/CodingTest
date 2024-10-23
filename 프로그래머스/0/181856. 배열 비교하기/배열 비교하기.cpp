#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
		int answer1 = 0, answer2 = 0;

	if (arr1.size() != arr2.size()) {
		if (arr1.size() > arr2.size()) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else {
		for (int i : arr1) {
			answer1 += i;
		}
		for (int i : arr2) {
			answer2 += i;
		}
		if (answer1 > answer2) {
			return 1;
		}
		if (answer1 < answer2) {
			return -1;
		}
		else {
			return 0;
		}
	}

}