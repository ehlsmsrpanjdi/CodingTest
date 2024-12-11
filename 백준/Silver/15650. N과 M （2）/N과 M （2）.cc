//ios::sync_with_stdio(0);
//cin.tie(0);
#include <iostream>
#include <vector>
using namespace std;

int N, M;

bool used[10];
int arr[10];

void print() {
	for (int i = 0; i < M; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

void fun(int _n, int _num) {
	if (_num == M) {
		print();
		return;
	}

	for (int i = _n; i <= N; ++i) {
		if (used[i] == false) {
			used[i] = true;
			arr[_num] = i;
			fun(i + 1, _num + 1);
			used[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	std::cin >> N >> M;
	fun(1, 0);
	return 0;
}