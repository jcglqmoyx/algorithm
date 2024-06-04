#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target) {
        int f[n + 1][target + 1];
        memset(f, 0x3f, sizeof f);
        f[0][0] = 0;
        for (int i = 0; i < m; i++) {
            int g[n + 1][target + 1];
            memset(g, 0x3f, sizeof g);
            int c = houses[i];
            if (c) {
                for (int u = 0; u <= n; u++) {
                    for (int k = 1; k <= min(target, i + 1); k++) {
                        g[c][k] = min(g[c][k], f[u][k - (c != u)]);
                    }
                }
            } else {
                for (int j = 1; j <= n; j++) {
                    for (int u = 0; u <= n; u++) {
                        for (int k = 1; k <= min(target, i + 1); k++) {
                            g[j][k] = min(g[j][k], f[u][k - (j != u)] + cost[i][j - 1]);
                        }
                    }
                }
            }
            memcpy(f, g, sizeof g);
        }
        int res = 0x3f3f3f3f;
        for (int j = 1; j <= n; j++) {
            res = min(res, f[j][target]);
        }
        return res >= 0x3f3f3f3f ? -1 : res;
    }
};