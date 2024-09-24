#include <string>
#include <vector>

#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

string solution(string myString) {
	std::transform(myString.begin(), myString.end(), myString.begin(), [](unsigned char c) {
		return std::toupper(c);
		});

	return myString;
}