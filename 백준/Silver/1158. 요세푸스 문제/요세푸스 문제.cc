#include <string>
#include <list>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


//int main() {
//	std::cout << ' ,';
//}

int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);

	std::list<int> llist;
	std::vector<int> solve;
	int num, count;
	cin >> num;
	for (int i = 1; i < num + 1; ++i) {
		llist.push_back(i);
	}
	std::list<int>::iterator iter = llist.begin();
	cin >> count;

	while (llist.size()) {
		for (int i = 0; i < count - 1; ++i) {
			++iter;
			if (iter == llist.end()) {
				iter = llist.begin();
			}
		}
		solve.push_back(*iter);
		iter = llist.erase(iter);
		if (iter == llist.end()) {
			iter = llist.begin();
		}
	}
	std::cout << '<';
	int i = 0;
	for (; i < solve.size() - 1; ++i) {
		std::cout << solve[i];
		std::cout << ", ";
	}
	std::cout << solve[i] << '>';
	return 0;
}