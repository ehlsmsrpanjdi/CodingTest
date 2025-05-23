#include "iostream"
#include "cmath"
#include "map"
#include "vector"
using namespace std;

long long d[10005];
int n;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	std::cin >> n;

	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= n; ++i) {
		d[i] = (d[i - 1] + d[i - 2]) % 10007;
	}

	std::cout << d[n];
}