class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		std::vector<std::vector<bool>> isVisited;
		isVisited.resize(grid.size(), std::vector<bool>(grid[0].size()));

		int row = grid.size();
		int col = grid[0].size();

		int drow[4] = { 1,0,-1,0 };
		int dcol[4] = { 0,1,0,-1 };

		int answer = 0;

		std::queue<std::pair<int, int>> qu;

		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (grid[i][j] == '1' && false == isVisited[i][j]) {
					++answer;
					qu.push(std::make_pair(i, j));
					isVisited[i][j] = true;
					while (!qu.empty()) {
						std::pair<int, int> pa = qu.front();
						qu.pop();

						for (int k = 0; k < 4; ++k) {
							int tempRow = pa.first + drow[k];
							int tempCol = pa.second + dcol[k];
							if (tempRow >= 0 && tempRow < row && tempCol >= 0 && tempCol < col) {
								if (isVisited[tempRow][tempCol] == false && grid[tempRow][tempCol] == '1') {
									qu.push(std::make_pair(tempRow, tempCol));
									isVisited[tempRow][tempCol] = true;
								}
							}
						}

					}
				}
			}
		}
		return answer;
	}
};