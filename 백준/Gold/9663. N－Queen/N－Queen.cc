//ios::sync_with_stdio(0);
//cin.tie(0);
#include <iostream>
#include <vector>
using namespace std;

const int N = 16; // 체스판의 크기

int num;
int num2;
// 상태 변수
bool colUsed[N];       // 열 체크
bool diag1Used[2 * N - 1]; // 왼쪽 위에서 오른쪽 아래 대각선 체크
bool diag2Used[2 * N - 1]; // 오른쪽 위에서 왼쪽 아래 대각선 체크

int Count = 0;

void fun(int _row) {
	if (_row == num) {
		++Count;
		return;
	}

	for (int i = 0; i < num; ++i) {
		if (colUsed[i] == true) continue;
		if (diag1Used[_row - i + num - 1] == true) continue;
		if (diag2Used[_row + i] == true) continue;
		colUsed[i] = true;
		diag1Used[_row - i + num - 1] = true;
		diag2Used[_row + i] = true;
		fun(_row + 1);
		colUsed[i] = false;
		diag1Used[_row - i + num - 1] = false;
		diag2Used[_row + i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	std::cin >> num;
	num2 = num * num;
	fun(0);
	std::cout << Count;
	return 0;
}