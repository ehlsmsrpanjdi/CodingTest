#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
	vector<int> answer;
	answer.resize(52, 0);
	for (char value : my_string) {
		if (value > 90) {
			value = value - 6;
		}
		int index = value - 'A';
		++answer[index];
	}
	return answer;
}
