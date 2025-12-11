#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;


int checkIndex(int index, int maxSize) {
	if (index >= maxSize) {
		return 0;
	}

	if (index < 0) {
		return maxSize - 1;
	}

	return index;
}

int solution(string name) {
	int answer = 0;

	int maxSize = name.size();

	int notACount = 0;

	int minCalculate = 0;

	for (int i = 0; i < maxSize; ++i) {
		if (name[i] != 'A') {
			++notACount;

			minCalculate += min('Z' + 1 - name[i], name[i] - 'A');
		}
	}

	answer = maxSize;

	int cachedCount = 0;
	string cachedString;

	for (int i = 0; i < maxSize; ++i) {
		int index = 0;
		int moveCount = 0;
		cachedCount = notACount;
		cachedString = name;
		while (true) {
			if (moveCount < i) {
				if (cachedString[index] != 'A') {
					--cachedCount;
					cachedString[index] = 'A';
				}
				++index;
				index = checkIndex(index, maxSize);
			}
			else {
				if (cachedString[index] != 'A') {
					--cachedCount;
					cachedString[index] = 'A';
				}
				--index;
				index = checkIndex(index, maxSize);
			}

			if (cachedCount <= 0) {
				break;
			}
			++moveCount;
		}

		if (moveCount < answer) {
			answer = moveCount;
		}
	}

	cachedString = name;

	for (int i = 0; i < maxSize; ++i) {
		int index = 0;
		int moveCount = 0;
		cachedCount = notACount;
		cachedString = name;
		while (true) {
			if (moveCount < i) {
				if (cachedString[index] != 'A') {
					cachedString[index] = 'A';
					--cachedCount;
				}
				--index;
				index = checkIndex(index, maxSize);
			}
			else {
				if (cachedString[index] != 'A') {
					cachedString[index] = 'A';
					--cachedCount;
				}
				++index;
				index = checkIndex(index, maxSize);
			}

			if (cachedCount <= 0) {
				break;
			}
			++moveCount;
		}

		if (moveCount < answer) {
			answer = moveCount;
		}
	}




	return answer + minCalculate;
}
