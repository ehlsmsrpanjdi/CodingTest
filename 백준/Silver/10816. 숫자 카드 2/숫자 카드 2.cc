//ios::sync_with_stdio(0);
//cin.tie(0);
#include "iostream"
#include "cmath"
#include "map"
#include "algorithm"
using namespace std;
int n;
std::map<int, int> ma;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	std::cin >> n;
	int value = 0;
	for (int i = 0; i < n; i++) {
		cin >> value;
		++ma[value];
	}
	int m;
	cin >> m;
	while (m--) {
		cin >> value;
		std::cout << ma[value] << ' ';
	}

}