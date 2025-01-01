#include "iostream"
#include "cmath"
#include "map"
#include "vector"
using namespace std;
int n;
int d[1000004];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	std::cin >> n;

	std::map<int, int> ma;

	d[0] = 0;
	d[1] = 0;
	d[2] = 1;
	d[3] = 1;

	ma[1] = 0;
	ma[2] = 1;
	ma[3] = 1;

	for (int i = 4; i <= n; ++i) {
		ma[i] = i - 1;
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0) {
			if (d[i] - 1 > d[i / 2]) {
				ma[i] = i / 2;
				d[i] = d[i / 2] + 1;
			}
		}
		if (i % 3 == 0) {
			if (d[i] - 1 > d[i / 3]) {
				ma[i] = i / 3;
				d[i] = d[i / 3] + 1;
			}
		}
	}
	std::cout << d[n] << '\n' << n << ' ';
	for (int i = n; i > 1 ;) {
		std::cout << ma[i] << ' ';
		i = ma[i];
	}

}