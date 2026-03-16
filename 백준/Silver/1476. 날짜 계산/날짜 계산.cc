#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;




int main() {
	int N, M, K;


	cin >> N >> M >> K;

	int counter = 1;

	while (!(N == 1 && M == 1 && K == 1)) {
		--N;
		--M;
		--K;
		++counter;

		if (N <= 0) {
			N = 15;
		}

		if (M <= 0) {
			M = 28;
		}

		if (K <= 0) {
			K = 19;
		}
	}

	std::cout << counter;


	return 0;
}
