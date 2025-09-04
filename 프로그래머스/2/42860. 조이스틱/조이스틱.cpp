#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
	int answer = 0;
	int lengthValue = name.size();
	int j;

	int moveValue = name.size() - 1;

	for (int i = 0; i < name.size(); ++i) {

		answer += std::min(name[i] - 'A', 'Z' - name[i] + 1);

		j = i + 1;


		while (j < name.size() && name[j] == 'A') {
			++j;
		}

		int tempValue = std::min(i + i + lengthValue - j, i + (lengthValue - j) * 2);

		moveValue = std::min(moveValue, tempValue);
	}


	return answer + moveValue;
}
