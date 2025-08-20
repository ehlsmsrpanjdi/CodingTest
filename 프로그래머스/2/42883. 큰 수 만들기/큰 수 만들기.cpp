#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
	string answer = "";


	int index = 0;
	while (k > 0 && index + 1 < number.size()) {
		if (number[index] < number[index + 1]) {
			number.erase(index, 1);
			--k;
			index = 0;
			continue;
		}
		else {
			++index;
		}
	}

	while (k > 0) {
		number.erase(number.end() - 1);
        --k;
	}

	return number;
}