#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<int> numbers, int target) {
	int answer = 0;

	std::queue<std::pair<int, int>> qu;
	int nSize = numbers.size();

	qu.push(std::make_pair(-numbers[0], 0));
	qu.push(std::make_pair(numbers[0], 0));

	std::pair<int, int> pa;

	while (!qu.empty()) {
		pa = qu.front();
		qu.pop();



		if (pa.second < nSize - 1) {
			qu.push(std::make_pair(pa.first + numbers[pa.second + 1], pa.second + 1));
			qu.push(std::make_pair(pa.first - numbers[pa.second + 1], pa.second + 1));
		}
		else if (pa.second == nSize - 1 && pa.first == target) {
			++answer;
		}


	}

	return answer;
}
