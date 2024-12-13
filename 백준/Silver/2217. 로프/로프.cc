#include "functional"
#include "iostream"
#include "algorithm"
using namespace std;


int n;
int w[100005];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> w[i];
	int answer = 0;
	sort(w, w + n);
	int max = w[n - 1];
	for (int i = 2; i <= n; ++i) {
		if ((i)*w[n - i] > max) {
			max = i * w[n - i];
		}
	}

	std::cout << max;

	return 0;
}

