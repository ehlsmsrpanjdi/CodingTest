#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	std::vector<int> one = { 1, 2, 3, 4, 5 };

	std::vector<int> two = { 2, 1, 2, 3, 2, 4, 2, 5 };

	std::vector<int> three = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	std::vector<int> answerVec = { 0,0,0 };


	for (int i = 0; i < answers.size(); ++i) {
		if (answers[i] == one[i % one.size()]) {
			++answerVec[0];
		}
		if (answers[i] == two[i % two.size()]) {
			++answerVec[1];
		}
		if (answers[i] == three[i % three.size()]) {
			++answerVec[2];
		}
	}

	if (answerVec[0] > answerVec[1]) {
		if (answerVec[0] > answerVec[2]) {
			return{ 1 };
		}
		else if (answerVec[0] == answerVec[2]) {
			return{ 1,3 };
		}
		else {
			return{ 3 };
		}
	}

	else if (answerVec[0] < answerVec[1]) {
		if (answerVec[1] > answerVec[2]) {
			return{ 2 };
		}
		else if (answerVec[1] == answerVec[2]) {
			return{ 2 ,3 };
		}
		else {
			return{ 3 };
		}
	}

	else {
		if (answerVec[0] > answerVec[2]) {
			return { 1,2 };
		}
		else if (answerVec[0] == answerVec[2]) {
			return { 1,2,3 };
		}
		else {
			return { 3 };
		}
	}
}