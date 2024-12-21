//ios::sync_with_stdio(0);
//cin.tie(0);
#include "iostream"
#include "cmath"
#include "map"
#include "algorithm"
#include "vector"
using namespace std;


int n;
int x[1000005];
vector<int> uni; // unique
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		uni.push_back(x[i]);
	}
	std::sort(uni.begin(), uni.end());
	uni.erase(std::unique(uni.begin(), uni.end()), uni.end());
	for (int i = 0; i < n; ++i) {
		std::cout << std::upper_bound(uni.begin(), uni.end(), x[i]) - uni.begin() - 1 << '\n';
	}
}