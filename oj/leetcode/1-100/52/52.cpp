#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int row = 0, col = 0;
        // d1: \, d2: /
        int d1 = 0, d2 = 0;
        int res = 0;
        int path[n][n];
        memset(path, 0, sizeof path);
        auto dfs = [&](auto &&dfs, int i, int j, int cnt) -> void {
            if (i == n) {
                if (cnt == n) {
                    res++;
                }
            } else if (j == n) {
                dfs(dfs, i + 1, 0, cnt);
            } else {
                dfs(dfs, i, j + 1, cnt);
                if (!(row >> i & 1 || col >> j & 1 || d1 >> (i - j + n) & 1 || d2 >> (i + j) & 1)) {
                    row ^= 1 << i;
                    col ^= 1 << j;
                    d1 ^= 1 << (i - j + n);
                    d2 ^= 1 << (i + j);
                    path[i][j] = true;
                    dfs(dfs, i, j + 1, cnt + 1);
                    path[i][j] = false;
                    row ^= 1 << i;
                    col ^= 1 << j;
                    d1 ^= 1 << (i - j + n);
                    d2 ^= 1 << (i + j);
                }
            }
        };
        dfs(dfs, 0, 0, 0);
        return res;
    }
};