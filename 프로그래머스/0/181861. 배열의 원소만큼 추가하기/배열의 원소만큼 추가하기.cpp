#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;
	for (int value : arr) {
		for (int i = 0; i < value; ++i) {
			answer.push_back(value);
		}
	}

	return answer;
}