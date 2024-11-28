#include <string>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


char board[2300][2300];

void solution(int left, int top, int right, int down) {

	int n = right - left;

	if (n <= 0) {
		return;
	}
	n /= 3;

	for (int i = left + n; i < left + 2 * n; ++i) {
		for (int j = top + n; j < top + n * 2; ++j) {
			board[j][i] = ' ';
		}
	}


	solution(left, top, left + n, top + n);
	solution(left + n, top, left + 2 * n, top + n);
	solution(left + 2 * n, top, left + 3 * n, top + n);

	solution(left, top + n, left + n, top + 2 * n);
	solution(left + 2 * n, top + n, left + 3 * n, top + 2 *  n);

	solution(left, top + 2 * n, left + n, top + 3 * n);
	solution(left + n, top + 2 * n, left + 2 * n, top + 3 * n);
	solution(left + 2 * n, top + 2 * n, left + 3 * n, top + 3 * n);




}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		memset(board[i], '*', n);
	}

	solution(0,0,n,n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << board[j][i];
		}
		std::cout << '\n';
	}


	int a = 0;

	return 0;
}