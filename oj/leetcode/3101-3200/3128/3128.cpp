#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>> &grid) {
        using ll = long long;
        ll res = 0;
        int n = grid.size(), m = grid[0].size();
        vector<int> row(n), col(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] && row[i] > 1 && col[j] > 1)
                    res += (row[i] - 1) * (col[j] - 1);
            }
        }
        return res;
    }
};