#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{


	if (s[0] != '(' && s[s.size() - 1] != ')') {
		return false;
	}

	int left = 0;
	int right = 0;

	for (char c : s) {
		if (left < 0) {
			return false;
		}
		if (c == '(') {
			++left;
		}
		else {
			--left;
		}
	}

	if (left == right) {
		return true;
	}


	return false;
}
