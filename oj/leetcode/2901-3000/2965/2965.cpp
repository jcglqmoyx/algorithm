#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
        vector<int> res(2);
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = abs(grid[i][j]);
                int r = (x - 1) / n, c = (x - 1 + n) % n;
                if (grid[r][c] < 0) res[0] = x;
                grid[r][c] = -grid[r][c];
            }
        }
        for (int x = 1, i = 0; i < n; i++) {
            for (int j = 0; j < n; j++, x++) {
                if (grid[i][j] > 0 && x != res[0]) {
                    res[1] = x;
                    return res;
                }
            }
        }
        return res;
    }
};