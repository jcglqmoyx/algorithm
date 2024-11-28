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
        deque<pair<int, int>> q;
        q.emplace_back(0, 0);
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop_front();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && f[nx][ny] > f[x][y] + grid[nx][ny]) {
                    f[nx][ny] = f[x][y] + grid[nx][ny];
                    if (grid[nx][ny]) {
                        q.emplace_back(nx, ny);
                    } else {
                        q.emplace_front(nx, ny);
                    }
                }
            }
        }
        return f[n - 1][m - 1];
    }
};