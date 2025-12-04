#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	int lostCount = n;

	unordered_map<int, bool> hasReserve;
	unordered_map<int, bool> lostReverse;

	for (int i : lost) {
		lostReverse[i] = true;
	}

	for (int i : reserve) {
		hasReserve[i] = true;
	}

	for (int i = 1; i <= n; ++i) {

		if (lostReverse[i] == true) {


			if (hasReserve[i] == true) {
				hasReserve[i] = false;
				--lostCount;
			}


			else if (hasReserve[i - 1] == true) {
				hasReserve[i - 1] = false;
				--lostCount;
			}

			else if (hasReserve[i + 1] == true) {
				if (lostReverse[i + 1] != true) {
					hasReserve[i + 1] = false;
					--lostCount;
				}
			}
		}
		else {
			--lostCount;
		}
	}


	return n - lostCount;
}