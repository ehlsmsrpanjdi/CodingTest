
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startcolor = image[sr][sc];
        image[sr][sc] = color;
        std::queue<std::pair<int, int>> qu;

        qu.push(std::make_pair(sr, sc));

        while (!qu.empty()) {
            std::pair<int,int> pa = qu.front();
            qu.pop();
            for (int i = 0; i < 4; ++i) {
                int tempx = pa.first + dx[i];
                int tempy = pa.second + dy[i];

                if (tempx >= 0 && tempy >= 0 && tempx < image.size() && tempy < image[0].size()) {
                    if (image[tempx][tempy] == startcolor && image[tempx][tempy] != color) {
                        image[tempx][tempy] = color;
                        qu.push(std::make_pair(tempx, tempy));
                    }
                }

            }
        }
        return image;
    }
};
