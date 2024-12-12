#include<iostream>
using namespace std;

int compare(int i, int j);

int main() {

	int N;

	cin >> N;

	int DP[301];

	int stair[301];

	for (int i = 1; i <= N; ++i) {
		cin >> stair[i];
	}

	DP[1] = stair[1];
	DP[2] = stair[1] + stair[2];
	DP[3] = compare(stair[1] + stair[3], stair[2] + stair[3]);

	for (int i = 4; i <= N; ++i) {
		DP[i] = compare(DP[i - 3] + stair[i - 1] + stair[i], DP[i - 2] + stair[i]);
	}

	printf("%d\n", DP[N]);
}

int compare(int i, int j) {
	if (i > j) return i;
	return j;
}