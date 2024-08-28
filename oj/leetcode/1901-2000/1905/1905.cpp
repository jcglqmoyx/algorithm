#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        auto n = grid1.size(), m = grid1[0].size();
        queue<pair<int, int>> q;
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid1[i][j] && grid2[i][j]) {
                    q.emplace(i, j);
                    bool ok = true;
                    grid2[i][j] = 0;
                    while (!q.empty()) {
                        auto t = q.front();
                        q.pop();
                        int x = t.first, y = t.second;
                        if (!grid1[x][y]) ok = false;
                        for (int u = 0; u < 4; u++) {
                            int a = x + dx[u], b = y + dy[u];
                            if (a >= 0 && a < n && b >= 0 && b < m && grid2[a][b]) {
                                q.emplace(a, b);
                                grid2[a][b] = 0;
                            }
                        }
                    }
                    res += ok;
                }
            }
        }
        return res;
    }
};