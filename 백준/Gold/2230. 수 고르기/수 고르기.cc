//ios::sync_with_stdio(0);
//cin.tie(0);
#include "iostream"
#include "cmath"
#include "map"
#include "algorithm"
#include "vector"
using namespace std;

int n, m;
int a[100005];
int mn = 0x7fffffff;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int st = 0;
	int en = 0;
	for (st = 0; st < n; ++st, en = st) {
		while (a[en] - a[st] < m && en < n - 1) {
			++en;
		}
		if (mn > a[en] - a[st] && a[en] - a[st] >= m) {
			mn = a[en] - a[st];
		}
	}


	cout << mn;
}