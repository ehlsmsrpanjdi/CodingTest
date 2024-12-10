#include <iostream>
#include <vector>
using namespace std;

int arr[10];
bool check[10];

int N, M;


void fun(int _n) {
	if (_n == M) {
		for (int i = 0; i < M; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << '\n';
	}

	for (int i = 1; i <= N; ++i) {
		if (check[i] == false) {
			arr[_n] = i;
			check[i] = true;
			fun(_n + 1);
			check[i] = false;
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	std::cin >> N >> M;
	fun(0);
}
