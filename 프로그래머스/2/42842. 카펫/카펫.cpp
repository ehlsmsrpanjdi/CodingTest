#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <stack>
#include <iostream>


using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	int value = sqrt(yellow);

	if (yellow == 1) {
		return { 3,3 };
	}

	else if (yellow == 2) {
		return { 4,3 };
	}

	for (int i = 1; i <= value; ++i) {
		if (yellow % i == 0) {
			int blockCount = i * 2 + yellow / i * 2 + 4;

			if (brown == blockCount) {
				answer.push_back(yellow / i + 2);
				answer.push_back(i + 2);
			}

		}
	}



	return answer;
}
