#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <cstring>
using namespace std;


int dist[1000][1000];
int arr[1000][1000];
bool visit[1000][1000];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1, 0,1,0 };
int x, y;
int rx, ry;
std::queue<std::pair<int, int>> qu;
int main() {
	cin >> x >> y;
	rx = x;
	ry = y;
	string line;
	int vechu;
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < x; ++i) {
		cin >> line;
		for (int j = 0; j < y; ++j) {
			arr[i][j] = line[j] - '0';
		}
	}
	qu.push(make_pair(0, 0));
	visit[0][0] = 1;
	dist[0][0] = 1;
	while (!qu.empty()) {
		std::pair<int,int> pa = qu.front();
		qu.pop();
		for (int i = 0; i < 4; ++i) {
			x = dx[i] + pa.first;
			y = dy[i] + pa.second;
			if (x < 0 || y < 0) {
				continue;
			}
			else if(arr[x][y] == 1 && visit[x][y] != true) {
				qu.push(make_pair(x, y));
				dist[x][y] = dist[pa.first][pa.second] + 1;
				visit[x][y] = true;
			}
		}
	}
	std::cout << dist[rx - 1][ry - 1];
}
