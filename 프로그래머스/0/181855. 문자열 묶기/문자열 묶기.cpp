#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<string> strArr) {
	int max = 0;
	std::map<int,int> strmap;
	for (std::string str : strArr) {
		++strmap[str.size()];
		if (strmap[str.size()] > max) {
			max = strmap[str.size()];
		}
	}

	return max;
}