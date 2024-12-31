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
	int N;
	std::cin >> N;
	int* ma = new int[1000005];
	ma[1] = 0;
	for (int i = 2; i <= N; ++i) {
		ma[i] = ma[i - 1] + 1;
		if (i % 2 == 0) ma[i] = min(ma[i], ma[i / 2] + 1);
		if (i % 3 == 0) ma[i] = min(ma[i], ma[i / 3] + 1);
	}
	std::cout << ma[N];

	return 0;
}