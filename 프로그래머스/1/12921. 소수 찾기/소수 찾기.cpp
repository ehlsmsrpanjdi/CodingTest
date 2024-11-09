#include <string>
#include <vector>
#include <cmath>
using namespace std;



int solution(int n) {
	int answer = n - 1;

	int* arr = new int[1000001];

	std::vector<int> vec;
	for (int i = 0; i < 1000001; ++i) {
		arr[i] = i;
	}

	int index = 0;
	for (int i = 2; i <= n; ++i) {
		for (int j = i + i; j <= n; j += i) {
			if (arr[j] != 0) {
				arr[j] = 0;
				--answer;
			}
		}
	}
	return answer;

}