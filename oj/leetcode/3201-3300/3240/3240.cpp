#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>> &grid) {
        int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size());
        if (n * m < 4) {
            int cnt1 = 0;
            for (auto &row: grid) {
                for (int x: row) {
                    cnt1 += x;
                }
            }
            return cnt1;
        }
        int res = 0;
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m / 2; j++) {
                int cnt1 = grid[i][j] + grid[n - i - 1][j] + grid[i][m - j - 1] + grid[n - i - 1][m - j - 1];
                res += min(cnt1, 4 - cnt1);
            }
        }
        int diff = 0, cnt1 = 0;
        if (n & 1) {
            int half = n / 2;
            for (int j = 0; j < m / 2; j++) {
                if (grid[half][j] != grid[half][m - j - 1]) {
                    diff++;
                } else if (grid[half][j]) {
                    cnt1 += 2;
                }
            }
        }
        if (m & 1) {
            int half = m / 2;
            for (int i = 0; i < n / 2; i++) {
                if (grid[i][half] != grid[n - i - 1][half]) {
                    diff++;
                } else if (grid[i][half]) {
                    cnt1 += 2;
                }
            }
            if (n & 1) {
                res += grid[n / 2][half];
            }
        }
        res += diff;
        if (!diff) {
            res += min(cnt1 % 4, 4 - cnt1 % 4) + diff;
        }
        return res;
    }
};