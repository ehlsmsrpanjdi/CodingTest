#include <iostream>
#include <queue>
using namespace std;


int dist[101][101];
bool visit[101][101];

int solution(vector<vector<int>> maps)
{
	std::queue<std::pair<int, int>> qu;
	int n, m;
	m = maps.size();  //y값이자 도착지
	n = maps[0].size();	//x값이자 도착지

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	qu.push(make_pair(0, 0));
	visit[0][0] = true;
	dist[0][0] = 1;

	while (!qu.empty()) {		//qu가 비어있지 않을 때 까지
		std::pair<int, int> pa = qu.front();

		qu.pop();

		if (pa.first == n - 1 && pa.second == m - 1) {
			return dist[pa.second][pa.first];
			//정답
		}

		int x = pa.first;
		int y = pa.second;

		int tempx;
		int tempy;

		for (int i = 0; i < 4; ++i) {
			tempx = x + dx[i];
			tempy = y + dy[i];

			if (tempx >= 0 && tempy >= 0 && tempx < n && tempy < m && (visit[tempy][tempx] == false)
				&& maps[tempy][tempx] == 1) {
				dist[tempy][tempx] = dist[y][x] + 1;
				visit[tempy][tempx] = true;
				qu.push(make_pair(tempx, tempy));
			}
		}
	}
	return -1;

}