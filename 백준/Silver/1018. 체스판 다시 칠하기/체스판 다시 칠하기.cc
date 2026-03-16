#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;




int main() {
	int N, M;


	cin >> N >> M;

	std::vector<std::vector<char>> vec(N, std::vector<char>(M));

	int counter = 100000000;

	int counter1 = 0;
	int counter2 = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cin >> vec[i][j];
		}
	}
	for (int row = 0; row <= N - 8; ++row) {
		for (int col = 0; col <= M - 8; ++col) {
			counter1 = 0;
			counter2 = 0;
			for (int i = row; i < 8 + row; ++i) {
				for (int j = col; j < 8 + col; ++j) {
					if (vec[i][j] == 'B') {
						if ((i + j) % 2) {
							++counter1;
						}
						else {
							++counter2;
						}
					}

					else if (vec[i][j] == 'W') {
						if ((i + j) % 2) {
							++counter2;
						}
						else {
							++counter1;
						}
					}
				}
			}
			if (counter1 < counter2) counter2 = counter1;
			if (counter2 < counter) counter = counter2;
		}
	}

	std::cout << counter;

	return 0;
}
