#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <unordered_map>
#include <deque>
#include <set>
#define X first
#define Y second
using namespace std;
int n, k;
std::map<int, int> jem;
multiset<int> bag;
pair<int, int> jewel[300003]; // {가격, 무게}

long long total = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	int m, v;
	for (int i = 0; i < n; i++)
		cin >> jewel[i].Y >> jewel[i].X;
	sort(jewel, jewel + n);

	int c;
	for (int i = 0; i < k; ++i) {
		std::cin >> c;
		bag.insert(c);
	}
	for (int i = n - 1; i >= 0; i--) {
		int m, v;
		tie(v, m) = jewel[i];
		auto it = bag.lower_bound(m);
		if (it == bag.end()) continue;
		total += v;
		bag.erase(it);
	}
	std::cout << total;
	return 0;
}