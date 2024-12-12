#include <iostream>
using namespace std;

#define MAX 1001

int min(int a, int b);
int min(int a, int b, int c);

int main() {

	int cost[MAX][4] = { 0, };
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> cost[i][1] >> cost[i][2] >> cost[i][3];

		cost[i][1] += min(cost[i - 1][2], cost[i - 1][3]);
		cost[i][2] += min(cost[i - 1][1], cost[i - 1][3]);
		cost[i][3] += min(cost[i - 1][1], cost[i - 1][2]);
	}

	cout << min(cost[N][1], cost[N][2], cost[N][3]) << '\n';
}

int min(int a, int b) {
	int result = (a <= b) ? a : b;  //a가 작으면 a반환 아니면 b반환하기

	return result;
}

int min(int a, int b, int c) {
	int result = (a <= b) ? a : b;
	result = (result <= c) ? result : c;
	return result;
}