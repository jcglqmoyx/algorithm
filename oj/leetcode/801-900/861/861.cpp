#include <bits/stdc++.h>

using namespace std;

/*
class Solution {
public:
    int matrixScore(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int flip = 0;
        for (int i = 0; i < n; i++) {
            if (!grid[i][0]) {
                flip |= 1 << i;
            }
        }
        int res = (1 << (m - 1)) * n;
        for (int j = 1; j < m; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] ^ (flip >> i & 1)) cnt++;
            }
            res += max(cnt, n - cnt) * (1 << (m - j - 1));
        }
        return res;
    }
};
 */


class Solution {
public:
    int matrixScore(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int ret = m * (1 << (n - 1));

        for (int j = 1; j < n; j++) {
            int n_ones = 0;
            for (int i = 0; i < m; i++) {
                if (grid[i][0] == 1) {
                    n_ones += grid[i][j];
                } else {
                    n_ones += (1 - grid[i][j]);
                }
            }
            int k = max(n_ones, m - n_ones);
            ret += k * (1 << (n - j - 1));
        }
        return ret;
    }
};