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



int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	std::vector<bool> visitComputer;
	std::queue<int> qu;

	visitComputer.resize(computers.size());


	std::vector<int> cacheVec;

	for (int i = 0; i < n; ++i) {
		if (visitComputer[i] == false) {
			qu.push(i);
			visitComputer[i] = true;
			++answer;
		}

		while (!qu.empty()) {
			int currentComputerNumber = qu.front();
			qu.pop();
			cacheVec = computers[currentComputerNumber];

			for (int j = 0; j < cacheVec.size(); ++j) {
				if (cacheVec[j] == true && visitComputer[j] == false) {
					visitComputer[j] = true;
					qu.push(j);
				}
			}
		}
	}


	return answer;
}
