#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>

using namespace std;


int main() {

	int N;

	std::cin >> N;


	std::vector<std::pair<int, int>> vec;

	std::vector<int> result;

	int x, y;

	for (int i = 0; i < N; ++i) {

		std::cin >> x >> y;

		vec.push_back({ x,y });
	}

	int count;

	for (int j = 0; j < N; ++j) {
		count = 0;
		for (int i = 0; i < N; ++i) {
			if (i == j)	continue;

			if (vec[j].first < vec[i].first && vec[j].second < vec[i].second) {
				++count;
			}

		}

		result.push_back(count + 1);
	}

	for (int i = 0; i < N; ++i) {
		std::cout << result[i] << " ";
	}
}