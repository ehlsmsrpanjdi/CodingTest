#include <string>
#include <vector>

using namespace std;
vector<int> solution(vector<int> arr, vector<bool> flag) {
	vector<int> answer;

	for (int i = 0; i < flag.size(); ++i) {
		int j = 0;
		if (flag[i]) {
			while (j++ < arr[i] * 2) {
				answer.push_back(arr[i]);
			}
		}
		else {
			while (j++ < arr[i]) {
				answer.pop_back();
			}
		}
	}

	return answer;
}