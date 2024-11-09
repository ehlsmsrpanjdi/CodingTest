#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(int a, int b) {
	string answer = "";
	int day = 0;
	if (a > 1) {
		day = b;
		a -= 1;
		while (a) {
			if (a <= 7) {
				if (a == 2) {
					day += 29;
				}
				else if (a % 2) {
					day += 31;
				}
				else {
					day += 30;
				}
			}
			else {
				if (a % 2 == 0) {
					day += 31;
				}
				else {
					day += 30;
				}
			}
			a -= 1;
		}
	}
	else {
		day = b;
	}
	std::map<int, std::string> dday;
	dday[1] = "FRI";
	dday[2] = "SAT";
	dday[3] = "SUN";
	dday[4] = "MON";
	dday[5] = "TUE";
	dday[6] = "WED";
	dday[7] = "THU";

	while (day >= 8) {
		day -= 7;
	}

	answer = dday[day];




	return answer;
}

