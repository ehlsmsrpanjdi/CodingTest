#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	std::unordered_map<int, int>priortyMap;

	std::queue<std::pair<int, int>> qu;
	std::map<int, bool> checkMap;

	for (int i = 0; i < priorities.size(); ++i) {
		++priortyMap[priorities[i]];
		qu.push(make_pair(priorities[i], i));
		checkMap[priorities[i]] = true;
	}

	std::map<int, bool>::iterator iter = checkMap.end();
	--iter;

	std::pair<int, int> val;

	int count = 1;

	while (!qu.empty()) {
		val = qu.front();
		qu.pop();
		if (val.first != (*iter).first) {
			qu.push(val);
			continue;
		}
		else {
			if (val.second == location) {
				return count;
			}
			--priortyMap[val.first];
			if (priortyMap[val.first] <= 0) {
				--iter;
			}
			++count;
		}
	}

	return answer;
}
