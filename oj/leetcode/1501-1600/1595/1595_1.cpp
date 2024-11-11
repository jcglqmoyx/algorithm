#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int connectTwoGroups(vector<vector<int>> &cost) {
        int n = cost.size(), m = cost[0].size();
        int prices[n][1 << m];
        memset(prices, 0, sizeof prices);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 1 << m; j++) {
                for (int k = 0; k < m; k++) {
                    if (j >> k & 1) {
                        prices[i][j] += cost[i][k];
                    }
                }
            }
        }
        int f[1 << m];
        memcpy(f, prices[0], sizeof prices[0]);
        for (int i = 1; i < n; i++) {
            int g[1 << m];
            memset(g, 0x3f, sizeof g);
            g[0] = 0;
            for (int j = 0; j < 1 << m; j++) {
                for (int k = (j - 1) & j; k; k = (k - 1) & j) {
                    g[j] = min(g[j], f[j ^ k] + prices[i][k]);
                }
                for (int k = 0; k < m; k++) {
                    if (j >> k & 1) {
                        g[j] = min(g[j], f[j] + cost[i][k]);
                    }
                }
            }
            memcpy(f, g, sizeof g);
        }
        return f[(1 << m) - 1];
    }
};