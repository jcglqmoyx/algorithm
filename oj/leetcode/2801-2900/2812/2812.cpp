#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>> &grid) {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        auto n = grid.size(), m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return 0;
        int f[n][m];
        memset(f, 0x3f, sizeof f);
        queue<pair<int, int>> q1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    f[i][j] = 0;
                    q1.emplace(i, j);
                }
            }
        }
        while (!q1.empty()) {
            for (auto it = q1.size(); it; it--) {
                auto t = q1.front();
                q1.pop();
                for (int i = 0; i < 4; i++) {
                    int a = t.first + dx[i], b = t.second + dy[i];
                    if (a >= 0 && a < n && b >= 0 && b < m && !grid[a][b] && f[a][b] > f[t.first][t.second] + 1) {
                        q1.emplace(a, b);
                        f[a][b] = f[t.first][t.second] + 1;
                    }
                }
            }
        }
        auto check = [&](int mid) {
            if (f[0][0] < mid) return false;
            bool st[n][m];
            memset(st, 0, sizeof st);
            queue<pair<int, int>> q2;
            q2.emplace(0, 0);
            st[0][0] = true;
            while (!q2.empty()) {
                auto t = q2.front();
                q2.pop();
                int x = t.first, y = t.second;
                for (int i = 0; i < 4; i++) {
                    int a = x + dx[i], b = y + dy[i];
                    if (a >= 0 && a < n && b >= 0 && b < m && !st[a][b] && f[a][b] >= mid) {
                        if (a == n - 1 && b == m - 1) return true;
                        q2.emplace(a, b);
                        st[a][b] = true;
                    }
                }
            }
            return false;
        };
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                r = max(r, f[i][j]);
            }
        }
        r = min(r, (int) n - 1);
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};