#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c) {
	int size = my_string.size();
	int index = c - 1;
	string answer = "";

	while (size > index) {
		answer += my_string[index];
		index += m;
	}

	return answer;
}
