#include "iostream"
#include "cmath"
#include "map"
#include "vector"
using namespace std;

int n, m;
int a[100004], d[100004];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i) {
		d[i] = d[i - 1] + a[i];
	}

	int i, j;
	for (int z = 0; z < m; ++z) {
	std::cin >> i >> j;
	std::cout << d[j] - d[i - 1] << '\n';
	}




}