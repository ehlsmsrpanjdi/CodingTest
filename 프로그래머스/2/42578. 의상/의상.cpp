#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	std::unordered_map<std::string, int> unMap;

	int clothesType = 0;

	for (std::vector<std::string> vec : clothes) {
		if (unMap[vec[1]] == 0) {
			++clothesType;
		}
		++unMap[vec[1]];
	}

	for (std::pair<const std::string, int>& pa : unMap) {
		answer *= (pa.second + 1);
	}


	return answer - 1;
}
