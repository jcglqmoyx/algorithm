#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>> &grid) {
        int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size());
        int f[n][m];
        memset(f, 0x3f, sizeof f);
        f[0][0] = 0;
        pair<int, int> q[n * m * 100];
        int hh = 0, tt = -1;
        q[++tt] = {0, 0};
        while (hh <= tt) {
            auto [x, y] = q[hh++];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && f[nx][ny] > f[x][y] + grid[nx][ny]) {
                    f[nx][ny] = f[x][y] + grid[nx][ny];
                    q[++tt] = {nx, ny};
                }
            }
        }
        return f[n - 1][m - 1];
    }
};