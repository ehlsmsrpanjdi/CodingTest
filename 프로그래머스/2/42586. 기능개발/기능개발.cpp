#include <unordered_map>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	vector<float> daysToComplete;

	int VectorSize = progresses.size();
	for (int i = 0; i < VectorSize; ++i) {
		float days = ceil((100 - progresses[i]) / (float)speeds[i]);
		daysToComplete.push_back(days);
	}

	float MinValue = daysToComplete.front();
	int Count = 1;

	for (int i = 1; i < VectorSize; ++i) {
		if (MinValue < daysToComplete[i]) {
			answer.push_back(Count);
			MinValue = daysToComplete[i];
			Count = 1;
		}
		else {
			Count++;
		}
	}
	if (Count > 0) {
		answer.push_back(Count);
	}

	return answer;
}

