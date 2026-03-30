#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

bool Checker(int num) {
	string str = std::to_string(num);
	if (str.find("666") != string::npos) {
		return true;
	}
	return false;
}

int main() {

	int N;

	std::cin >> N;

	int count = 0;

	int answer = 666;

	while (true) {
		if (true == Checker(answer)) {
			++count;
			if (count == N) {
				std::cout << answer << std::endl;
				break;
			}
		}
		++answer;
	}
}