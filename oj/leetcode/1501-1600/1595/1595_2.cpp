#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int connectTwoGroups(vector<vector<int>> &cost) {
        int n = cost.size(), m = cost[0].size();
        int f[1 << n];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            int g[1 << m];
            memset(g, 0x3f, sizeof g);
            for (int s = 0; s < 1 << m; s++) {
                for (int j = 0; j < m; j++) {
                    g[s | (1 << j)] = min(g[s | (1 << j)], f[s] + cost[i][j]);
                    g[s | (1 << j)] = min(g[s | (1 << j)], g[s] + cost[i][j]);
                }
            }
            memcpy(f, g, sizeof g);
        }
        return f[(1 << m) - 1];
    }
};