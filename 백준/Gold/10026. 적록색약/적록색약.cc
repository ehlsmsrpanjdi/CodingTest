#include "iostream"
#include "list"
#include "algorithm"
#include "stack"
#include "queue"
using namespace std;
char board[101][101];
bool vis[101][101];
int n;
int col = 0;
int ncol = 0;
int di[4] = { 1,0,-1,0 };
int dj[4] = { 0,1,0,-1 };
void color(int _i, int _j);
void none_color(int _i, int _j);
void reset() {
	for (int i = 0; i < 101; ++i) {
		for (int j = 0; j < 101; ++j) {
			vis[i][j] = false;
		}
	}
}

void check() {

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (vis[i][j] == false) {
				++col;
				color(i, j);
			}
		}
	}
	reset();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (vis[i][j] == false) {
				if (board[i][j] == 'G') {
					board[i][j] = 'R';
				}
				++ncol;
				none_color(i, j);
			}
		}
	}
}
void color(int _i, int _j) {
	std::queue<std::pair<int, int>> qu;
	qu.push(make_pair(_i, _j));


	while (!qu.empty()) {
		std::pair<int, int> pa = qu.front();
		qu.pop();

		int tempi, tempj;
		for (int i = 0; i < 4; ++i) {
			tempi = pa.first + di[i];
			tempj = pa.second + dj[i];

			if (tempi >= 0 && tempj >= 0 && tempj < n && tempi < n) {
				if (vis[tempi][tempj] == false && board[tempi][tempj] == board[pa.first][pa.second]) {
					vis[tempi][tempj] = true;
					qu.push(make_pair(tempi, tempj));
				}
			}
		}
	}
}

void none_color(int _i, int _j) {
	std::queue<std::pair<int, int>> qu;
	qu.push(make_pair(_i, _j));


	while (!qu.empty()) {
		std::pair<int, int> pa = qu.front();
		qu.pop();

		int tempi, tempj;
		for (int i = 0; i < 4; ++i) {
			tempi = pa.first + di[i];
			tempj = pa.second + dj[i];
			if (board[tempi][tempj] == 'G') {
				board[tempi][tempj] = 'R';
			}
			if (tempi >= 0 && tempj >= 0 && tempj < n && tempi < n) {
				if (vis[tempi][tempj] == false) {
					if (board[tempi][tempj] == board[pa.first][pa.second]) {
						vis[tempi][tempj] = true;
						qu.push(make_pair(tempi, tempj));
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	check();

	std::cout << col << ' ' << ncol;
	return 0;
}