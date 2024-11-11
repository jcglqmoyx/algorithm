#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>> &grid) {
        auto n = grid.size(), m = grid[0].size();
        vector<int> res(m);
        for (int j = 0; j < m; j++) {
            int max_width = 0;
            for (int i = 0; i < n; i++) {
                max_width = max(max_width, (int) to_string(grid[i][j]).size());
            }
            res[j] = max_width;
        }
        return res;
    }
};