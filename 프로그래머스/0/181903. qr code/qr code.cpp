#include <string>
#include <vector>

using namespace std;

string solution(int q, int r, string code) {
	int size = code.size();
	int index = r;
	string answer = "";

	while (size > index) {
		answer += code[index];
		index += q;
	}

	return answer;
}