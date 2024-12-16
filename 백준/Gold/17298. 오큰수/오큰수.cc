#include "iostream"
#include "list"
#include "algorithm"
#include "stack"
#include "queue"
using namespace std;
#define ll long long

stack<std::pair<int,int>> s;
int n;
int ans[1000002];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	ll h;
	ll count = n;
	ans[n] = -1;
	while (n) {
		cin >> h;
		while (!s.empty() && h > s.top().first) {
			ans[s.top().second] = h;
			s.pop();
		}
		s.push(make_pair(h, count - n));
		--n;
	}


	for (int i = 0; i < count; ++i) {
		if (ans[i] == 0) {
			std::cout << -1 << ' ';
			continue;
		}
		std::cout << ans[i] << ' ';
	}

	return 0;
}