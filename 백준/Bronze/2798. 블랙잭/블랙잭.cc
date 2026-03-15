#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int main() {
	int N, M;

	cin >> N >> M;

	vector<int> cards(N);

	for (int i = 0; i < N; i++) {
		cin >> cards[i];
	}

	int Prev = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N && i != j; ++j) {
			for (int k = 0; k < N && k != j && k != i; ++k) {
				int Total = cards[i] + cards[j] + cards[k];
				if (Total > M) {
					continue;
				}
				if (Total == M) {
					std::cout << Total;
					return 0;
				}
				else {
					int sub = abs(M - Total);
					int subPrev = abs(M - Prev);

					if (sub < subPrev) {
						Prev = Total;
					}
				}
			}
		}
	}
	std::cout << Prev;
	return 0;
}
