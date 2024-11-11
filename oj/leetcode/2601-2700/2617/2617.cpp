#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int minimumVisitedCells(vector<vector<int> > &grid) {
        int n = grid.size(), m = grid[0].size(), INF = 0x3f3f3f3f;
        int f[n][m];
        memset(f, 0x3f, sizeof f);
        f[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 || f[i][j] == INF) continue;
                int start = i + 1, limit = min(grid[i][j] + i, n - 1);
                if (i && f[i - 1][j] == f[i][j]) start = grid[i - 1][j] + i;
                for (int r = start; r <= limit; r++) {
                    f[r][j] = min(f[r][j], f[i][j] + 1);
                }
                start = j + 1, limit = min(grid[i][j] + j, m - 1);
                if (j && f[i][j - 1] == f[i][j]) start = grid[i][j - 1] + j;
                for (int c = start; c <= limit; c++) {
                    f[i][c] = min(f[i][c], f[i][j] + 1);
                }
            }
        }
        return f[n - 1][m - 1] == INF ? -1 : f[n - 1][m - 1];
    }
};