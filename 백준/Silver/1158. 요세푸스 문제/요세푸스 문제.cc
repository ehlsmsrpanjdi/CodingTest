#include "iostream"
#include "list"
#include "algorithm"

int main() {

	int N, M;
	std::cin >> N >> M;
	std::list<int> li;

	for (int i = 1; i <= N; ++i) {
		li.push_back(i);
	}
	int count = M;
	std::list<int>::iterator iter = li.begin();
	
	for (int i = 0; i < count - 1; ++i) {
		++iter;
		if (iter == li.end()) {
			iter = li.begin();
		}
	}

	if (li.size() == 1) {
		std::cout << '<' << *iter << '>';
		return 0;
	}

	std::cout << '<' << *iter << ", ";
	iter = li.erase(iter);
	if (iter == li.end()) {
		iter = li.begin();
	}
	while (li.size() != 0) {
		for (int i = 0; i < count - 1; ++i) {
			++iter;
			if (iter == li.end()) {
				iter = li.begin();
			}
		}
		if (li.size() == 1) {
			std::cout << *iter << '>';
			return 0;
		}

		std::cout << *iter << ", ";
		iter = li.erase(iter);
		if (iter == li.end()) {
			iter = li.begin();
		}
	}
}