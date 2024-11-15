#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>> &grid) {
        int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size());
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int l = 0, r = m - 1; l < r; l++, r--) {
                cnt += grid[i][l] != grid[i][r];
            }
        }
        int res = cnt;
        cnt = 0;
        for (int j = 0; j < m; j++) {
            for (int l = 0, r = n - 1; l < r; l++, r--) {
                cnt += grid[l][j] != grid[r][j];
            }
        }
        return min(res, cnt);
    }
};