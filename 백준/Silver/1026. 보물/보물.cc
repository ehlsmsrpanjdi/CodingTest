#include "functional"
#include "iostream"
#include "algorithm"
using namespace std;


int a[105], b[105];
int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int answer = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(a, a + n);
	sort(b, b + n);

	for (int i = 0; i < n; ++i) {
		answer += a[i] * b[n - 1 - i];
	}
	std::cout << answer;
	return 0;
}

