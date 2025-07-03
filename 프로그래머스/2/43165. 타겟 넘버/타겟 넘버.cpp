#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cstring>
using namespace std;

int solution(vector<int> numbers, int target) {
	int answer = 0;
	std::queue<std::pair<int, int>> qu;
	int numberSize = numbers.size();
	qu.push(std::make_pair(numbers[0], 0));
	qu.push(std::make_pair(-numbers[0], 0));

	while (!qu.empty()) {
		std::pair<int,int> pa =  qu.front();

		qu.pop();

		if (pa.second < numberSize - 1) {
			qu.push(std::make_pair(pa.first + numbers[pa.second + 1], pa.second + 1));
			qu.push(std::make_pair(pa.first - numbers[pa.second + 1], pa.second + 1));
		}
		else if (pa.second == numberSize - 1) {
			if (pa.first == target) {
				++answer;
			}
		}
	}

	return answer;
}
