#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

bool isvisited[101][101];
int distanceMap[101][101];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int solution(vector<vector<int>> maps)
{
	int answer = 0;

	std::queue<std::pair<int, int>> qu;

	qu.push(std::make_pair(0, 0));
	distanceMap[0][0] = 1;

	std::pair<int, int> pa;
	while (!qu.empty()) {
		pa = qu.front();

		if (pa.first == maps.size()-1 && pa.second == maps[0].size()-1) {
			return distanceMap[pa.first][pa.second];
		}

		qu.pop();
		for (int i = 0; i < 4; ++i) {
			int tempx = pa.first + dx[i];
			int tempy = pa.second + dy[i];
			if (tempx >= 0 && tempx < maps.size() && tempy >= 0 && tempy < maps[0].size())
			{
				if (maps[tempx][tempy] == 1) {
					if (isvisited[tempx][tempy] == false) {
						isvisited[tempx][tempy] = true;
						qu.push(make_pair(tempx, tempy));
						distanceMap[tempx][tempy] = distanceMap[pa.first][pa.second] + 1;
					}
				}
			}
		}
	}

	return -1;
}

