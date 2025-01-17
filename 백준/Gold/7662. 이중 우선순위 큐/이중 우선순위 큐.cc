#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <unordered_map>
#include <deque>
#include <set>
using namespace std;

int n;
int m;
char Select;
int num;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	multiset<int> Se;
	std::cin >> n;
	while (n--) {
		std::cin >> m;
		while (m--) {
			std::cin >> Select >> num;
			switch (Select)
			{
			case 'I':
			{
				Se.insert(num);
			}
			break;
			case 'D':
			{
				if (Se.empty() == true || Se.size() == 1) {
					Se.clear();
					break;
				}
				if (num == -1) {
					Se.erase(Se.begin());
				}
				else {
					Se.erase(std::prev(Se.end()));
				}
			}
			break;
			default:
				break;
			}
		}
		if (Se.empty() == true) {
			std::cout << "EMPTY\n";
		}
		else {
			std::cout << *std::prev(Se.end()) << " " << *Se.begin() << '\n';
		}
		Se.clear();
	}
}