#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;




int main() {

	int N, M;


	cin >> N >> M;

	std::vector<std::vector<char>> vec(N, std::vector<char>(M));
	char a = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; ++j) {
			cin >> a;
			vec[i][j] = a;
		}
	}

	int mincounter = 64;


	for (int i = 0; i <= N - 8; ++i) {
		for (int j = 0; j <= M - 8; ++j) {
			int counter = 0;

			int divide = 0;
			if ((i + j) % 2 != 0) {
				divide = 1;
			}

			for (int k = i; k < i + 8; ++k) {
				for (int l = j; l < j + 8; ++l) {
					if ((k + l) % 2 == divide && vec[k][l] != 'B') {
						++counter;
					}

					if ((k + l) % 2 != divide && vec[k][l] != 'W') {
						++counter;
					}
				}
			}

			if (counter > 32) {
				counter = 64 - counter;
			}

			if (counter < mincounter) {
				mincounter = counter;
			}
		}
	}

	std::cout << mincounter;
}
