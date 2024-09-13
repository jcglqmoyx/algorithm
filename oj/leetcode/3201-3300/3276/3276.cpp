#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>> &grid) {
        auto n = grid.size();
        int mx = 0;
        for (auto &r: grid) {
            mx = max(mx, *max_element(r.begin(), r.end()));
        }
        vector<vector<int>> pos(mx + 1);
        for (int i = 0; i < n; i++) {
            for (int x: grid[i]) {
                pos[x].emplace_back(i);
            }
        }
        for (auto &r: pos) {
            sort(r.begin(), r.end());
            r.erase(unique(r.begin(), r.end()), r.end());
        }
        int f[mx + 1][1 << n];
        memset(f, -1, sizeof f);

        auto dp = [&](auto &&dp, int i, int j) -> int {
            if (i == 0 || j == 0) return 0;
            if (f[i][j] != -1) return f[i][j];
            f[i][j] = dp(dp, i - 1, j);
            if (!pos[i].empty()) {
                for (int r: pos[i]) {
                    if (j >> r & 1) {
                        f[i][j] = max(f[i][j], i + dp(dp, i - 1, j ^ (1 << r)));
                    }
                }
            }
            return f[i][j];
        };
        return dp(dp, mx, (1 << n) - 1);
    }
};