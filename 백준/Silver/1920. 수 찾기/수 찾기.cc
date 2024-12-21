//ios::sync_with_stdio(0);
//cin.tie(0);
#include "iostream"
#include "vector"
#include "list"
#include "map"
#include "queue"
#include "algorithm"
using namespace std;
int a[100005];
int n;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	std::cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int m;
	cin >> m;
	while (m--) {
		int t;
		cin >> t;
		cout << binary_search(a, a + n, t) << '\n';
	}

}