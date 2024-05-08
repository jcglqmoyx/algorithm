#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTime(vector<vector<int>> &grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        int n = grid.size(), m = grid[0].size();
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        int f[n][m];
        memset(f, 0x3f, sizeof f);

        struct T {
            int x, y;
            int time;

            bool operator<(const T &t) const {
                return time > t.time;
            }
        };

        priority_queue<T> q;
        q.emplace(0, 0, 0);
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            if (f[t.x][t.y] <= t.time) continue;
            f[t.x][t.y] = t.time;
            for (int i = 0; i < 4; i++) {
                int x = t.x + dx[i], y = t.y + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && f[x][y] > f[t.x][t.y] + 1) {
                    if (grid[x][y] > f[t.x][t.y] + 1) {
                        int diff = grid[x][y] - f[t.x][t.y];
                        q.emplace(x, y, f[t.x][t.y] + diff + (diff % 2 == 0));
                    } else {
                        q.emplace(x, y, f[t.x][t.y] + 1);
                    }
                }
            }
        }
        return f[n - 1][m - 1];
    }
};