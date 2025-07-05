#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cstring>
using namespace std;




int BFS(std::vector<std::vector<int>>& _vec, int _ignore, int _Size) {
	std::vector<std::vector<int>> vec;
	std::vector<bool> isVisited;
	isVisited.resize(_Size + 1, false);
	vec.resize(_Size + 1, std::vector<int>());
	for (int i = 0; i < _vec.size(); ++i) {
		if (_ignore == i) {
			continue;
		}
		vec[_vec[i][0]].push_back(_vec[i][1]);
		vec[_vec[i][1]].push_back(_vec[i][0]);
	}

	std::queue<int> qu;
	int Count = 0;
	for (int i = 0; i < vec.size(); ++i) {
		if (isVisited[i] == false && vec[i].size() != 0) {
			++Count;
			if (Count != 1) {
				int a = 0;
				for (bool visited : isVisited) {
					if (visited == true) {
						++a;
					}
				}
				return _Size - a * 2;
			}

			isVisited[i] = true;
			for (int val : vec[i]) {
				qu.push(val);
			}
		}

		while (!qu.empty()) {
			int node = qu.front();
			qu.pop();

			if (isVisited[node] == false && vec[node].size() != 0) {
				isVisited[node] = true;
				for (int val : vec[node]) {
					qu.push(val);
				}
			}
		}
	}

	int a = 0;
	for (bool visited : isVisited) {
		if (visited == true) {
			++a;
		}
	}
	return _Size - a * 2;
}

int solution(int n, vector<vector<int>> wires) {
	int answer = -1;

	int minValue = n;

	for (int i = 0; i < wires.size(); ++i) {
		minValue = std::min(minValue,  std::abs(BFS(wires, i, n)));
	}

	return minValue;
}
