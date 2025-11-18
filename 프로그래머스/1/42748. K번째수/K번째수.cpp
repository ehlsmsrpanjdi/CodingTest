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

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (auto& vec : commands) {
		std::vector<int> tempvec = array;
		std::sort(tempvec.begin() + vec[0] - 1, tempvec.begin() + vec[1]);

		answer.push_back(tempvec[vec[0] + vec[2] - 2]);
	}

	return answer;
}