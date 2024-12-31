#include "iostream"
#include "cmath"
#include "map"
#include "vector"
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;

	std::vector<bool> vec(1001, true);
	int count = 0;
	for (int i = 2; i <= n; ++i) {
		if (vec[i] != false) {
			int temp = i;
			for (int j = i; j <= n; j += temp) {
				if (vec[j] != false) {
					vec[j] = false;
					++count;
				}
				if (count == k) {
					std::cout << j << std::endl;
					return 0;
				}
			}
		}
	}

}