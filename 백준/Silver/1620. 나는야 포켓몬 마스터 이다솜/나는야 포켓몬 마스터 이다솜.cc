#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#include <string>
#include <vector>
#include <map>

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	std::cin >> n >> m;
	std::string str;
	std::map<std::string, std::string> ma;
	std::map<std::string, std::string> am;

	for (int i = 1; i <= n; ++i) {
		std::cin >> str;
		ma[str] = std::to_string(i);
		am[std::to_string(i)] = str;
	}

	for (int i = 0; i < m; ++i) {
		std::cin >> str;
		if (ma.find(str) == ma.end()) {
			std::cout << am[str] << '\n';
		}
		else {
			std::cout << ma[str] << '\n';
		}
	}
	return 0;

}
