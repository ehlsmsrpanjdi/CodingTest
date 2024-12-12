//ios::sync_with_stdio(0);
//cin.tie(0);
#include "iostream"
#include "vector"
#include "list"
#include "map"
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, Count;
	std::cin >> Count;
	int* ma = new int[1000005];
	ma[1] = 1;
	ma[2] = 2;
	ma[3] = 4;//  3, 1 1 1 , 1 2, 2 1


	while (Count--) {
		std::cin >> N;
		for (int i = 4; i <= N; ++i) {
			ma[i] = ma[i - 1] + ma[i - 2] + ma[i - 3];
		}
		std::cout << ma[N] << '\n';
	}



	return 0;
}