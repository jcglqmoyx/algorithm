#include <bits/stdc++.h>

using namespace std;

/*
class Solution {
public:
    int cherryPickup(vector<vector<int>> &grid) {
        int n = grid.size();
        int f[n * 2 + 1][n + 1][n + 1];
        memset(f, -0x3f, sizeof f);
        f[2][1][1] = grid[0][0];
        for (int k = 3; k <= n * 2; k++) {
            for (int i = max(1, k - n); i <= min(n, k - 1); i++) {
                for (int j = max(1, k - n); j <= min(n, k - 1); j++) {
                    if (grid[i - 1][k - i - 1] == -1 || grid[j - 1][k - j - 1] == -1) continue;
                    int t = grid[i - 1][k - i - 1];
                    if (i != j) t += grid[j - 1][k - j - 1];
                    for (int a = i - 1; a <= i; a++) {
                        for (int b = j - 1; b <= j; b++) {
                            f[k][i][j] = max(f[k][i][j], f[k - 1][a][b] + t);
                        }
                    }
                }
            }
        }
        return max(f[n * 2][n][n], 0);
    }
};
 */

class Solution {
public:
    int cherryPickup(vector<vector<int>> &grid) {
        int n = grid.size();
        int f[n + 1][n + 1];
        memset(f, -0x3f, sizeof f);
        f[1][1] = grid[0][0];
        for (int k = 3; k <= n * 2; k++) {
            int g[n + 1][n + 1];
            memset(g, -0x3f, sizeof f);
            for (int i = max(1, k - n); i <= min(n, k - 1); i++) {
                for (int j = max(1, k - n); j <= min(n, k - 1); j++) {
                    if (grid[i - 1][k - i - 1] == -1 || grid[j - 1][k - j - 1] == -1) continue;
                    int t = grid[i - 1][k - i - 1];
                    if (i != j) t += grid[j - 1][k - j - 1];
                    for (int a = i - 1; a <= i; a++) {
                        for (int b = j - 1; b <= j; b++) {
                            g[i][j] = max(g[i][j], f[a][b] + t);
                        }
                    }
                }
            }
            memcpy(f, g, sizeof g);
        }
        return max(f[n][n], 0);
    }
};