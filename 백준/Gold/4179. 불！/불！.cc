#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
#define X first
#define Y second
string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		fill(dist1[i], dist1[i] + m, -1);
	}
	for (int i = 0; i < n; i++)
		cin >> board[i];
	queue<pair<int, int> > FQ;
	std::vector<pair<int, int>> JV;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'F') {
				FQ.push({ i,j });
				dist1[i][j] = -2;
			}
			if (board[i][j] == 'J') {
				JV.push_back({ i,j });
				dist1[i][j] = 0;
			}
		}
	}
	FQ.push(JV.front());

	while (!FQ.empty()) {
		std::pair<int, int> pa = FQ.front();
		FQ.pop();
		std::pair<int, int> temp;
		int rx, ry;

		if ((pa.first == 0 || pa.second == 0) || pa.first == (n - 1) || (pa.second == m - 1)) {
			if (dist1[pa.first][pa.second] != -2) {
				std::cout << dist1[pa.first][pa.second] + 1;
				return 0;
			}
		}

		for (int i = 0; i < 4; ++i) {
			rx = pa.first - dx[i];
			ry = pa.second - dy[i];

			if (rx >= 0 && ry >= 0 && rx < n && ry < m) {
				if (board[rx][ry] == '.') {
					if (dist1[rx][ry] == -1) {
						if (dist1[pa.first][pa.second] == -2) {
							dist1[rx][ry] = -2;
							FQ.push(make_pair(rx, ry));
						}
						else {
							dist1[rx][ry] = dist1[pa.first][pa.second] + 1;
							FQ.push(make_pair(rx, ry));
						}

					}
				}
			}
		}
	}


	std::cout << "IMPOSSIBLE"; // 여기에 도달했다는 것은 탈출에 실패했음을 의미.
}