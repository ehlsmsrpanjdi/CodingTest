#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	std::map<std::string, int> includeSet;

	for (std::string str : completion) {
		++includeSet[str];
	}

	for (std::string str : participant) {
		--includeSet[str];
		if (includeSet[str] < 0) {
			return str;
		}
	}

	return "";
}
