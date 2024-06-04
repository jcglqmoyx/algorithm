#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target) {
        const int INF = 0x3f3f3f3f;
        int f[target][n + 3];
        memset(f, 0x3f, sizeof f);
        memset(f[0], 0, sizeof f[0]);
        for (int i = 0; i < m; i++) {
            for (int section = min(i, target - 1); section >= 0; section--) {
                f[section][n + 1] = INF;
                f[section][n + 2] = INF;
                for (int color = 0; color < n; color++) {
                    if (houses[i] != 0 && color != houses[i] - 1) {
                        f[section][color] = INF;
                        continue;
                    }
                    f[section][color] = min(f[section][color], section == 0 ? INF : color == f[section - 1][n] ? f[section - 1][n + 2] : f[ section - 1][n + 1]) + (houses[i] == 0 ? cost[i][color] : 0);
                    if (f[section][color] < f[section][n + 1]) {
                        f[section][n] = color;
                        f[section][n + 2] = f[section][n + 1];
                        f[section][n + 1] = f[section][color];
                    } else if (f[section][color] < f[section][n + 2]) {
                        f[section][n + 2] = f[section][color];
                    }
                }
            }
        }
        return f[target - 1][n + 1] < INF ? f[target - 1][n + 1] : -1;

    }
};