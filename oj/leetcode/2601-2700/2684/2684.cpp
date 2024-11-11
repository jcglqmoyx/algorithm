#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>> &grid) {
        int dx[3] = {-1, 0, 1};
        auto n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size());
        int f[n][m];
        memset(f, -1, sizeof f);
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            q.emplace(i, 0);
            f[i][0] = 0;
        }
        int res = 0;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            for (int i: dx) {
                int a = t.first + i, b = t.second + 1;
                if (a >= 0 && a < n && b < m && grid[a][b] > grid[x][y] && f[a][b] <= f[x][y]) {
                    q.emplace(a, b);
                    f[a][b] = f[x][y] + 1;
                    res = max(res, f[a][b]);
                }
            }
        }
        return res;
    }
};