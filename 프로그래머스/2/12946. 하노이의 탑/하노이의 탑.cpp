#include <string>
#include <vector>

using namespace std;

std::vector<std::vector<int>> vec;



void hanoi(int n, int start, int end, int sub) {

	if (n == 1) {
		vec.push_back({ start, end });
		return;
	}

	//N - 1을 sub
	//N을 end로 
	//N - 1을 end

	hanoi(n - 1, start, sub, end);
	vec.push_back({ start, end });
	hanoi(n - 1, sub, end, start);

	return;
}



vector<vector<int>> solution(int n) {
	hanoi(n, 1, 3, 2);
	return vec;
}



