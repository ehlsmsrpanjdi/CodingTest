#include <string>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

//int main() {
//	std::list<int> li;
//	li.push_back(1);
//	li.push_back(2);
//	li.push_back(3);
//	li.push_back(4);
//	std::list<int>::iterator iter =  li.begin();
//	iter = li.insert(iter,5);
//	for (int i : li) {
//		std::cout << i << "\n";
//	}
//	std::cout << *iter;
//}

int main() {
	std::list<char> llist;
	std::list<char>::iterator iter;
	std::string str;
	char ch;
	std::cin >> str;
	for (char c : str) {
		llist.push_back(c);
	}
	iter = llist.end();
	int count = 0;
	cin >> count;
	while (count--) {
		cin >> ch;
		if (ch == 'L') {
			if (iter == llist.begin()) {
				continue;
			}
			--iter;
		}
		else if (ch == 'D') {
			if (iter == llist.end()) {
				continue;
			}
			++iter;
		}
		else if (ch == 'B') {
			if (iter == llist.begin()) {
				continue;
			}
			--iter;
			iter = llist.erase(iter);
		}
		else if (ch == 'P') {
			cin >> ch;
			if (iter == llist.begin()) {
				llist.insert(iter, ch);
				continue;
			}
			llist.insert(iter, ch);
		}
	}
	for (char c : llist) {
		std::cout << c;
	}
}