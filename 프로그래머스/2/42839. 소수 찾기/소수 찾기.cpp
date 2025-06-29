#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <iostream>

using namespace std;
unordered_set<int> unset;
int numberSize = 0;
std::vector<bool> isVisited;
string useValue;

bool IsPrime(int _Value) {
	if (_Value == 1 || _Value == 0) {
		return false;
	}
	for (int i = 2; i * i <= _Value; ++i) {
		if (_Value % i == 0) {
			return false;
		}
	}
	return true;
}

void BackTracking(string current) {
	if (!current.empty()) {
		int num = stoi(current);
		if (true == IsPrime(num)) {
			unset.insert(num);
		}
	}

	for (int i = 0; i < numberSize; ++i) {
		if (false == isVisited[i]) {
			isVisited[i] = true;
			BackTracking(current + useValue[i]);
			isVisited[i] = false;
		}
	}
}


int solution(string numbers) {
	int answer = 0;


	numberSize = numbers.size();


	useValue = numbers;
	isVisited.resize(numberSize, false);

	BackTracking("");
	for (int value : unset) {
		std::cout << value << std::endl;
	}

	return unset.size();
}