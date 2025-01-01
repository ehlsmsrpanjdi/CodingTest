#include "iostream"
#include "cmath"
#include "map"
#include "vector"
#include "algorithm"
using namespace std;
int n;
std::pair<int, int> ppap[100005];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int count = 0;
	std::multimap<int, int> ma;
	int i, j;
	int current = -1;
	for (int x = 0; x < n; x++) {
		std::cin >> ppap[x].second >> ppap[x].first;
	}
	std::sort(ppap, ppap + n);
	for (int i = 0; i <= n; ++i) {
		if (current <= ppap[i].second) {
			current = ppap[i].first;
			++count;
		}
	}
	std::cout << count;
}