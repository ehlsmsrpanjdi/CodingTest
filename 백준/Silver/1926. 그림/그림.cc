#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <cstring>
using namespace std;


int Count = 0;
int x, y;
int mmin = 0, mmax = 0;
int locationx, locationy;
int bug = 0;
int arr[1000][1000];
bool check[1000][1000];
std::vector<std::pair<int, int>> vec;
std::queue<std::pair<int, int>> vechu_qu;
std::pair<int, int> qu_pair;
void paircheck(std::pair<int, int>& qu_pair);

void BFS() {
	while (!vechu_qu.empty()) {
		qu_pair = vechu_qu.front();
		paircheck(qu_pair);
		vechu_qu.pop();
	}
}

void paircheck(std::pair<int, int>& qu_pair) {
	if (arr[qu_pair.first][qu_pair.second + 1] == 1 && !check[qu_pair.first][qu_pair.second + 1]) {
		check[qu_pair.first][qu_pair.second + 1] = true;
		vechu_qu.push(make_pair(qu_pair.first, qu_pair.second + 1));
		++bug;
	}
	if (arr[qu_pair.first + 1][qu_pair.second] == 1 && !check[qu_pair.first + 1][qu_pair.second]) {
		check[qu_pair.first + 1][qu_pair.second] = true;
		vechu_qu.push(make_pair(qu_pair.first + 1, qu_pair.second));
		++bug;
	}
	if (qu_pair.first - 1 >= 0) {
		if (arr[qu_pair.first - 1][qu_pair.second] == 1 && !check[qu_pair.first - 1][qu_pair.second]) {
			check[qu_pair.first - 1][qu_pair.second] = true;
			vechu_qu.push(make_pair(qu_pair.first - 1, qu_pair.second));
			++bug;
		}
	}
	if (qu_pair.second - 1 >= 0) {
		if (arr[qu_pair.first][qu_pair.second - 1] == 1 && !check[qu_pair.first][qu_pair.second - 1]) {
			check[qu_pair.first][qu_pair.second - 1] = true;
			vechu_qu.push(make_pair(qu_pair.first, qu_pair.second - 1));
			++bug;
		}
	}
}


int main() {

	cin >> x >> y;
	int exist;
	int vechu;
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			cin >> exist;
			arr[i][j] = exist;
			if (exist == 1) {
				vec.push_back(make_pair(i, j));
			}
		}
	}

	for (std::pair<int, int>& pp : vec) {
		bug = 0;
		if (check[pp.first][pp.second] != true) {
			vechu_qu.push(pp);
			check[pp.first][pp.second] = true;
			++mmin;
			++bug;
			BFS();
		}

		if (mmax < bug) {
			mmax = bug;
		}

	}

	std::cout << mmin << '\n';
	std::cout << mmax << '\n';
}
