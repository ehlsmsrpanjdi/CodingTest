#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

void func(int left, int right, int up, int down, vector<vector<int>>& arr, vector<int>& answer) {

	std::vector<int> vec;

	if (right - left == 1) {
		return;
	}

	for (int i = left; i < (left + right) / 2; ++i) {   //좌측상단
		for (int j = up; j < (up + down) / 2; ++j) {
			vec.push_back(arr[i][j]);
		}
	}

	if (vec.size() == 1) {
		if (vec[0] == 0) {
			++answer[0];
		}
		else {
			++answer[1];
		}
	}
	else if (*max_element(vec.begin(), vec.end()) == *min_element(vec.begin(), vec.end())) {
		if (vec[0] == 0) {
			++answer[0];
		}
		else {
			++answer[1];
		}
	}
	else {
		func(left, (left + right) / 2, up, (up + down) / 2, arr, answer);
	}


	vec.clear();

	for (int i = left; i < (left + right) / 2; ++i) {     //좌측 하단
		for (int j = (up + down) / 2; j < down; ++j) {
			vec.push_back(arr[i][j]);
		}
	}

	if (vec.size() == 1) {
		if (vec[0] == 0) {
			++answer[0];
		}
		else {
			++answer[1];
		}
	}
	else if (*max_element(vec.begin(), vec.end()) == *min_element(vec.begin(), vec.end())) {
		if (vec[0] == 0) {
			++answer[0];
		}
		else {
			++answer[1];
		}
	}
	else {
		func(left, (left + right) / 2, (up + down) / 2, down, arr, answer);
	}


	vec.clear();

	for (int i = (left + right) / 2; i < right; ++i) {	//우측상단
		for (int j = up; j < (up + down) / 2; ++j) {
			vec.push_back(arr[i][j]);
		}
	}

	if (vec.size() == 1) {
		if (vec[0] == 0) {
			++answer[0];
		}
		else {
			++answer[1];
		}
	}
	else if (*max_element(vec.begin(), vec.end()) == *min_element(vec.begin(), vec.end())) {
		if (vec[0] == 0) {
			++answer[0];
		}
		else {
			++answer[1];
		}
	}
	else {
		func((left + right) / 2, right, up, (up + down) / 2, arr, answer);
	}

	vec.clear();

	for (int i = (left + right) / 2; i < right; ++i) {   //우측하단
		for (int j = (up + down) / 2; j < down; ++j) {
			vec.push_back(arr[i][j]);
		}
	}

	if (vec.size() == 1) {
		if (vec[0] == 0) {
			++answer[0];
		}
		else {
			++answer[1];
		}
	}
	else if (*max_element(vec.begin(), vec.end()) == *min_element(vec.begin(), vec.end())) {
		if (vec[0] == 0) {
			++answer[0];
		}
		else {
			++answer[1];
		}
	}
	else {
		func((left + right) / 2, right, (up + down) / 2, down, arr, answer);
	}

}

vector<int> solution(vector<vector<int>> arr) {
	vector<int> answer;

	answer.push_back(0);
	answer.push_back(0);

	if (*std::max_element(arr.begin(), arr.end()) == *std::min_element(arr.begin(), arr.end())) {
		if (arr[0][0] == 1) {
			++answer[1];
		}
		else {
			++answer[0];
		}

		return answer;
	}


	int boxLength = arr.size();


	func(0, boxLength, 0, boxLength, arr, answer);



	return answer;
}