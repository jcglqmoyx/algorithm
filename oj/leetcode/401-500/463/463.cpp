#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        auto n = grid.size(), m = grid[0].size();
        int dx[2] = {1, 0};
        int dy[2] = {0, 1};
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    res += 4;
                    for (int u = 0; u < 2; u++) {
                        int a = i + dx[u], b = j + dy[u];
                        if (a < n && b < m && grid[a][b]) {
                            res -= 2;
                        }
                    }
                }
            }
        }
        return res;
    }
};