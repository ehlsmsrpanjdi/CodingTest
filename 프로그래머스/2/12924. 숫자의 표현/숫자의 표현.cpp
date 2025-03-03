#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	int i = 1; int j = 1;
	int total = 1;

	while (true) {
		if (j >= n || j > n / 2 + 10) {
			break;
		}
		if (total > n) {
			total -= i++;
		}
		else if (total < n) {
			total += ++j;
		}
		if (total == n) {
			++answer;
			total -= i++;
		}
	}


	return answer + 1;
}
