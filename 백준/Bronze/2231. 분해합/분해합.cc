#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int digitSum(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main() {
	int N;

	cin >> N;

	int temp = N;

	int count = 0;

	while (temp) {
		temp /= 10;
		++count;
	}


	int num = 1;

	int maxValue = num * 10;

	for (int num = 1; num <= N; num++) {
		if (N == digitSum(num) + num) {
			cout << num;
			return 0;
		}
	}

	std::cout << 0;

	return 0;
}
