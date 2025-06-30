#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <iostream>

using namespace std;


std::vector<bool> isUsed;
std::unordered_set<int> unSet;

bool IsPrime(int _Value) {
	if (0 == _Value || 1 == _Value) {
		return false;
	}

	for (int i = 2; i * i <= _Value; ++i) {
		if (_Value % i == 0) {
			return false;
		}
	}
	return true;
}

void BackTracking(string current, const string& _str) {

	if (0 != current.size()) {
		int Value = std::stoi(current);
		if (true == IsPrime(Value)) {
			unSet.insert(Value);
		}
	}


	for (int i = 0; i < isUsed.size(); ++i) {
		if (false == isUsed[i]) {
			isUsed[i] = true;
			BackTracking(current + _str[i], _str);
			isUsed[i] = false;
		}
	}
}

int solution(string numbers) {
	int answer = 0;
	isUsed.resize(numbers.size(), false);
	BackTracking("", numbers);

	return unSet.size();
}
