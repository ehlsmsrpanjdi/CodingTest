#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int remain;
	int currentDay = 0;
	int currentCount = -1;
	for (int i = 0; i < progresses.size(); ++i) {


		remain = std::ceil(((100 - progresses[i]) / float(speeds[i])));

		if (currentDay < remain) {
			answer.push_back(1);
			++currentCount;
			currentDay = remain;
		}
		else {
			++answer[currentCount];
		}
	}


	return answer;
}
