#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
	int answer = 0;

	vector<string> answer1;
	for (int i = 0; i < my_string.size(); ++i) {
		answer1.push_back(my_string.substr(0, i));
	}

	for (std::string str : answer1) {
		if(str == is_suffix){
			answer = 1;
		}
	}

	return answer;
}