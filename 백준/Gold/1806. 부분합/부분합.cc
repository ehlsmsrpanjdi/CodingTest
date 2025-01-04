#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int a[100005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int j = 0;
	int MValue = 0x7fffffff;
	int TValue = 0;

	for (int i = 0; i < n; ++i) {
		TValue += a[i];
		if (a[i] >= m) {
			std::cout << 1;
			return 0;
		}
		while (TValue >= m && j < i) {
			if (i - j + 1 < MValue) {
				MValue = i - j + 1;
			}
			TValue -= a[j++];
		}
	}
	if (MValue == 0x7fffffff) {
		std::cout << 0;
		return 0;
	}
	std::cout << MValue;
}