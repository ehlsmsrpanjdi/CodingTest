#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <cstring>
using namespace std;


int Count = 0;
int x, y;
int locationx, locationy;
int bug = 0;
int arr[100][100];
bool check[100][100];
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
	}
	if (arr[qu_pair.first + 1][qu_pair.second] == 1 && !check[qu_pair.first + 1][qu_pair.second]) {
		check[qu_pair.first + 1][qu_pair.second] = true;
		vechu_qu.push(make_pair(qu_pair.first + 1, qu_pair.second));
	}
	if (qu_pair.first - 1 >= 0) {
		if (arr[qu_pair.first - 1][qu_pair.second] == 1 && !check[qu_pair.first - 1][qu_pair.second]) {
			check[qu_pair.first - 1][qu_pair.second] = true;
			vechu_qu.push(make_pair(qu_pair.first - 1, qu_pair.second));
		}
	}
	if (qu_pair.second - 1 >= 0) {
		if (arr[qu_pair.first][qu_pair.second - 1] == 1 && !check[qu_pair.first][qu_pair.second - 1]) {
			check[qu_pair.first][qu_pair.second - 1] = true;
			vechu_qu.push(make_pair(qu_pair.first, qu_pair.second - 1));
		}
	}
}


int main() {

	cin >> Count;
	int vechu;
	while (Count--) {
		memset(arr, 0, sizeof(arr));
		memset(check, false, sizeof(check));
		vec.clear();
		cin >> x >> y >> vechu;
		while (vechu--) {
			cin >> locationx >> locationy;
			arr[locationx][locationy] = 1;
			vec.push_back(make_pair(locationx, locationy));
		}
		for (std::pair<int, int>& pp : vec) {
			if (check[pp.first][pp.second] != true) {
				vechu_qu.push(pp);
				check[pp.first][pp.second] = true;
				++bug;
				BFS();
			}
		}
		std::cout << bug << '\n';
		bug = 0;
	}
}