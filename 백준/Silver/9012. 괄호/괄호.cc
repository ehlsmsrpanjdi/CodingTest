#include <unordered_map>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <string>


int main()
{
	int count = 0;
	std::cin >> count;


	std::string str;
	for (int i = 0; i < count; ++i) {
		std::cin >> str;

		int left = 0;
		int right = 0;
		bool check = false;
		for (int j = 0; j < str.size(); ++j) {
			
			if (str[j] == '(') {
				++left;
			}
			else if (str[j] == ')') {
				++right;
			}
			if (right > left) {
				std::cout << "NO\n";
				check = true;
				break;
			}
		}
		if (check) {
			continue;
		}
		if (left == right) {
			std::cout << "YES\n";
		}
		else {
			std::cout << "NO\n";
		}
	}


}