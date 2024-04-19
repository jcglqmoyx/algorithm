#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        auto n = grid.size(), m = grid[0].size();
        bool st[n][m];
        memset(st, 0, sizeof st);
        function<void(int, int)> dfs = [&](int x, int y) {
            st[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a >= 0 && a < n && b >= 0 && b < m && grid[a][b] & 1 && !st[a][b]) {
                    dfs(a, b);
                }
            }
        };
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] & 1 && !st[i][j]) {
                    res++;
                    dfs(i, j);
                }
            }
        }
        return res;
    }
};