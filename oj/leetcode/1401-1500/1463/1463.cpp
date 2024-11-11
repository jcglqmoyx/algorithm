#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int f[m][m];
        memset(f, -0x3f, sizeof f);
        f[0][m - 1] = grid[0][0] + grid[0][m - 1];
        for (int r = 1; r < n; r++) {
            int g[m][m];
            memset(g, -0x2f, sizeof f);
            for (int i = 0; i < m; i++) {
                for (int j = i; j < m; j++) {
                    int t = grid[r][i];
                    if (i != j) t += grid[r][j];
                    for (int a = i - 1; a <= i + 1; a++) {
                        for (int b = j - 1; b <= j + 1; b++) {
                            if (a != b && a >= 0 && a < m && b >= 0 && b < m) {
                                g[i][j] = max(g[i][j], f[a][b] + t);
                            }
                        }
                    }
                }
            }
            memcpy(f, g, sizeof g);
        }
        int res = -1e8;
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                res = max(res, f[i][j]);
            }
        }
        return res;
    }
};