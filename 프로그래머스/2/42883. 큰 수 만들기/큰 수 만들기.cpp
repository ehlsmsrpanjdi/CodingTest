#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

string solution(string number, int k) {
	string answer = "";

	int i = 0;

	int maxSize = number.size();

	while (k > 0 && i < maxSize) {
		if (answer.empty() == true) {
			answer += number[i++];
		}
		else {
			while (answer.empty() != true && k > 0 && answer.back() < number[i]) {
				answer.pop_back();
				--k;
			}
			answer += number[i++];
		}
	}

	if (i != maxSize) {
		answer.append(number.begin() + i, number.end() - k);
	}

	if (k > 0) {
		while (k > 0) {
			answer.pop_back();
			--k;
		}
	}


	return answer;
}
