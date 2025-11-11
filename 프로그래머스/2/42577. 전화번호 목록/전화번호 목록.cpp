#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	std::sort(phone_book.begin(), phone_book.end());

	for (int i = 0; i < phone_book.size() - 1; ++i)
	{
		if (phone_book[i].size() > phone_book[i + 1].size()) {
			continue;
		}

		if (0 == phone_book[i + 1].find(phone_book[i])) {
			return false;
		}
	}


	return answer;
}
