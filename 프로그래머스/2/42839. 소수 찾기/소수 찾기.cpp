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

bool IsPrime(int _num) {

	if (_num == 1 || _num == 0) {
		return false;
	}

	if (_num == 2) {
		return true;
	}

	int value = std::sqrt(_num);

	for (int i = 2; i <= value; ++i) {
		if (_num % i == 0) {
			return false;
		}
	}

	return true;
}

void dfs(int& answer, set<int>& numSet, string current, string remain) {

	int value = 1;
	if (current.size() != 0) {
		value = stoi(current);
	}

	if (numSet.find(value) == numSet.end()) {
		numSet.insert(value);
		if (IsPrime(value) == true) {
			++answer;
		}
	}


	for (int i = 0; i < remain.size(); ++i) {
		dfs(answer, numSet, current + remain[i], remain.substr(0, i) + remain.substr(i + 1));
	}

}


int solution(string numbers) {
	int answer = 0;

	set<int> numSet;

	dfs(answer, numSet, "", numbers);


	return answer;
}
