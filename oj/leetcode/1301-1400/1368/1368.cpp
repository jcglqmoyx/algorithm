#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>> &grid) {
        int dx[] = {0, 0, 0, 1, -1};
        int dy[] = {0, 1, -1, 0, 0};
        auto n = grid.size(), m = grid[0].size();
        int f[n][m];
        memset(f, 0x3f, sizeof f);
        f[0][0] = 0;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            for (int i = 1; i <= 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a >= 0 && a < n && b >= 0 && b < m) {
                    int c = grid[x][y] != i;
                    if (f[a][b] > f[x][y] + c) {
                        f[a][b] = f[x][y] + c;
                        q.emplace(a, b);
                    }
                }
            }
        }
        return f[n - 1][m - 1];
    }
};