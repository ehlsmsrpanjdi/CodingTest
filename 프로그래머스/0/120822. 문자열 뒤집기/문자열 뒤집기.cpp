#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string my_string) {
	std::reverse(my_string.begin(), my_string.end());
	return my_string;
}