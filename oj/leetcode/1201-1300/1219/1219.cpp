#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>> &grid) {
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        auto n = grid.size(), m = grid[0].size();
        bool st[n][m];
        memset(st, 0, sizeof st);
        function<int(int, int)> dfs = [&](int x, int y) -> int {
            st[x][y] = true;
            int res = 0;
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a >= 0 && a < n && b >= 0 && b < m && grid[a][b] && !st[a][b]) {
                    res = max(res, dfs(a, b));
                }
            }
            st[x][y] = false;
            return res + grid[x][y];
        };
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) res = max(res, dfs(i, j));
            }
        }
        return res;
    }
};