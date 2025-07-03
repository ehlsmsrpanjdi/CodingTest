#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cstring>
using namespace std;

int compareString(const string& first, const string& second) {
	int Count = 0;
	for (int i = 0; i < first.size(); ++i) {
		if (first[i] == second[i]) {
			++Count;
		}
	}
	return Count;
}

int solution(string begin, string target, vector<string> words) {
	std::unordered_map<string, bool> isVisited;
	int answer = 0;

	std::queue<std::pair<string, int>> qu;

	qu.push(std::make_pair(begin, 0));

	while (!qu.empty()) {
		std::pair<string, int> pair = qu.front();



		qu.pop();

		for (const string& _str : words) {
			if (isVisited[_str] == false) {
				int Count =compareString(pair.first, _str);
				if (Count == pair.first.size() - 1) {
					if (target == _str) {
						return pair.second + 1;
					}
					qu.push(std::make_pair(_str, pair.second + 1));
					isVisited[_str] = true;
				}
			}
		}

	}

	return answer;
}