#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <unordered_map>
using namespace std;


string board[10];
int n, m, k;
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
unordered_map<string, int> cnt;

void dfs(int i, int j, string s) {
    ++cnt[s];
    if (s.size() >= 5) {
        return;
    }
    int tempi, tempj;
    for (int f = 0; f < 8; ++f) {
        tempi = (i + dx[f] + n) % n;
        tempj = (j + dy[f] + m) % m;
        if (tempi < 0 || tempj < 0 || tempi >= n || tempj >= m) {
            return;
        }
        dfs(tempi, tempj, s + board[tempi][tempj]);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> board[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) dfs(i, j, string(1, board[i][j]));
    while (k--) {
        string s;
        cin >> s;
        cout << cnt[s] << '\n';
    }
}