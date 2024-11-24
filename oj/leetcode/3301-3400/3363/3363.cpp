#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>> &fruits) {
        int n = static_cast<int> (fruits.size());
        int diagonal = 0;
        for (int i = 0; i < n; i++) {
            diagonal += fruits[i][i];
        }
        if (n == 1) return diagonal;

        int dt[3] = {-1, 0, 1};

        int f[n][n];
        memset(f, 0, sizeof f);
        f[0][n - 1] = fruits[0][n - 1];
        f[n - 1][0] = fruits[n - 1][0];
        for (int i = 1; i < n; i++) {
            for (int j = n - 1; j > max({(n - 1) / 2, i, n - i - 2}); j--) {
                for (int k: dt) {
                    int y = j + k;
                    if (y >= 0 && y < n) {
                        f[i][j] = max(f[i][j], f[i - 1][y] + fruits[i][j]);
                    }
                }
            }
        }
        for (int j = 1; j < n; j++) {
            for (int i = n - 1; i > max({(n - 1) / 2, j, n - j - 2}); i--) {
                for (int k: dt) {
                    int x = i + k;
                    if (x >= 0 && x < n) {
                        f[i][j] = max(f[i][j], f[x][j - 1] + fruits[i][j]);
                    }
                }
            }
        }
        return diagonal + f[n - 2][n - 1] + f[n - 1][n - 2];
    }
};