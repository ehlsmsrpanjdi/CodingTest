#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	std::unordered_set<int> unSet;

	answer = n - lost.size();

    	std::sort(lost.begin(), lost.end());
    
	for (int i : reserve) {
		unSet.insert(i);
	}

	for (std::vector<int>::iterator iter = lost.begin(); iter != lost.end();) {
		if (unSet.find(*iter) != unSet.end()) {
			unSet.erase(*iter);
			iter = lost.erase(iter);
			++answer;
		}
		else {
			++iter;
		}
	}


	for (int i : lost) {
		if (unSet.find(i - 1) != unSet.end()) {
			unSet.erase(i - 1);
			++answer;
		}
		else if (unSet.find(i + 1) != unSet.end()) {
			unSet.erase(i + 1);
			++answer;
		}
	}

	return answer;
}