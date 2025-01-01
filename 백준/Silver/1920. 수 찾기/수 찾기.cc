#include "iostream"
#include "cmath"
#include "map"
#include "vector"
#include "algorithm"
using namespace std;
int a[100005];
int n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	std::vector<int> vec;
	for (int i = 0; i < n; i++) {
		int value;
		std::cin >> value;
		vec.emplace_back(value);
	}
	sort(vec.begin(),vec.end());

	cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> m;
		if(!(std::binary_search(vec.begin(), vec.end(), m))){
			std::cout << "0\n";
		}
		else {
			std::cout << "1\n";
		}
	}
}