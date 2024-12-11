//ios::sync_with_stdio(0);
//cin.tie(0);
#include <iostream>
#include <vector>
using namespace std;

int N, M;

int arr[10];

void print() {
	for (int i = 0; i < M; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

void fun(int _n) {
	if (_n == M) {
		print();
		return;
	}
	for (int i = 1; i <= N; ++i) {
		arr[_n] = i;
		fun(_n + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	std::cin >> N >> M;
	fun(0);
	return 0;
}