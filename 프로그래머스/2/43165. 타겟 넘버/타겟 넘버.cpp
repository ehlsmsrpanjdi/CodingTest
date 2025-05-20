#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

std::queue<int> st;
int answer = 0;

void DFS(int _total, int _size, int _target, std::vector<int>& vec, int _index) {

	if (_size == _index + 1) {
		if (_total == _target) {
			++answer;
		}
		return;
	}
	DFS(_total - vec[_index + 1], _size, _target, vec, _index + 1);
	DFS(_total + vec[_index + 1], _size, _target, vec, _index + 1);
}

int solution(vector<int> numbers, int target) {

	int total = 0;
	DFS(numbers[0], numbers.size(), target, numbers, 0);
	DFS(-numbers[0], numbers.size(), target, numbers, 0);

	return answer;
}