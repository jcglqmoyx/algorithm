#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
        auto n = grid.size(), m = grid[0].size();
        vector<vector<int>> res(n - 2, vector<int>(m - 2));
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                int mx = 0;
                for (int r = i - 1; r <= i + 1; r++) {
                    for (int c = j - 1; c <= j + 1; c++) {
                        mx = max(mx, grid[r][c]);
                    }
                }
                res[i - 1][j - 1] = mx;
            }
        }
        return res;
    }
};