#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

const int MX = 1000005;
int dat[2 * MX + 1];
int head = MX, tail = MX+1;
int dsize = 0;

void push_front(int x) {
		dat[head--] = x;
		++dsize;

}
void push_back(int x) {
		dat[tail++] = x;
		++dsize;

}
void pop_front() {
	if (dsize != 0) {
		std::cout << dat[++head] << '\n';
		--dsize;
	}
	else {
		std::cout << -1 << '\n';
	}
}
void pop_back() {
	if (dsize != 0) {
		std::cout << dat[--tail] << '\n';
		--dsize;
	}
	else {
		std::cout << -1 << '\n';
	}
}
void front() {
	if (dsize != 0) {
		std::cout << dat[head + 1] << '\n';
	}
	else {
		std::cout << -1 << '\n';
	}
}
void back() {
	if (dsize != 0) {
		std::cout << dat[tail - 1] << '\n';
	}
	else {
		std::cout << -1 << '\n';
	}
}

void size() {
	std::cout << dsize << '\n';
}

void empty() {
	if (dsize) {
		std::cout << 0 << '\n';
	}
	else {
		std::cout << 1 << '\n';
	}
}

int main() {
	int N = 0;
	int num = 0;
	std::cin >> N;
	std::string str;
	while (N--) {
		cin >> str;
		if (str == "push_back") {
			std::cin >> num;
			push_back(num);
		}
		else if (str == "push_front") {
			std::cin >> num;
			push_front(num);
		}
		else if (str == "pop_front") {
			pop_front();
		}
		else if (str == "pop_back") {
			pop_back();
		}
		else if (str == "size") {
			size();
		}
		else if (str == "empty") {
			empty();
		}
		else if (str == "front") {
			front();
		}
		else if (str == "back") {
			back();
		}
	}

	return 0;
}