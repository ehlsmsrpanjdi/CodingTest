#include<iostream>
using namespace std;

int compare(int i, int j);

int main() {
	int N;
	cin >> N;
	int DP[10*10*10*10*10*10] = { 0,0,1,1, };

	for (int i = 4; i <= N; ++i) {
		if (i % 3 == 0 && i % 2 == 0) {
			DP[i] = 1 + compare(compare(DP[i / 3], DP[i / 2]), DP[i - 1]);
		}
		else if (i % 3 != 0 && i % 2 == 0) {
			DP[i] = 1 + compare(DP[i / 2], DP[i - 1]);
		}
		else if (i % 3 == 0 && i % 2 != 0) {
			DP[i] = 1 + compare(DP[i / 3], DP[i - 1]);
		}
		else if (i % 3 != 0 && i % 2 != 0) {
			DP[i] = 1 + DP[i - 1];
		}
	}

	cout << DP[N] << endl;
}

int compare(int i, int j) {
	if (i <= j) return i;
	return j;
}