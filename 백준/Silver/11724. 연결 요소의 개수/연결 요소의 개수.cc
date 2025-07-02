#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cstring>
using namespace std;

std::vector<std::vector<int>> graph;
bool visited[1001];

int main()
{
	int N, M;


	std::cin >> N >> M;


	graph.resize(N + 1, std::vector<int>());
	int n, m;
	for (int i = 0; i < M; ++i) {
		std::cin >> n >> m;
		graph[n].push_back(m);
		graph[m].push_back(n);
	}

	for (int i = 0; i <= N; ++i) {
		visited[i] = false;
	}


	std::queue<std::pair<int, int>> qu;
	std::pair<int, int> pa;
	int Count = 0;

	for (int i = 1; i <= N; ++i) {
		if (visited[i] == true) {
			continue;
		}
		++Count;
		visited[i] = true;
		for (int value : graph[i]) {
			qu.push(std::make_pair(i, value));
		}
		while (!qu.empty()) {
			pa = qu.front();
			qu.pop();
			if (visited[pa.second] == true) {
				continue;
			}
			visited[pa.second] = true;
			for (int paValue : graph[pa.second]) {
				qu.push(std::make_pair(pa.second, paValue));
			}
		}
	}
	std::cout << Count;


	return 0;
}
