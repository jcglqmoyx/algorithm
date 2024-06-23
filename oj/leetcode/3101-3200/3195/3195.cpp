#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>> &grid) {
        int min_row = 1e8, min_col = 1e8, max_row = 0, max_col = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    min_row = min(min_row, i);
                    max_row = i;
                    min_col = min(min_col, j);
                    max_col = max(max_col, j);
                }
            }
        }
        return (max_row - min_row + 1) * (max_col - min_col + 1);
    }
};