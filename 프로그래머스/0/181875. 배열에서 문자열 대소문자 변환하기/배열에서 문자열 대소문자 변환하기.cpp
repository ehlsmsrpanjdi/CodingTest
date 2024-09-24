#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;


vector<string> solution(vector<string> strArr) {

	for (int i = 0; i < strArr.size(); ++i) {
		if (i % 2) {
			std::transform(strArr[i].begin(), strArr[i].end(), strArr[i].begin(), [](unsigned char c) {
				return std::toupper(c);
				});
		}
		else {
			std::transform(strArr[i].begin(), strArr[i].end(), strArr[i].begin(), [](unsigned char c) {
				return std::tolower(c);
				});
		}
	}

	return strArr;
}