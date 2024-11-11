#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees) {
        auto n = passingFees.size();
        // f[i][j]: the minimum cost to reach city j within time i
        int f[maxTime + 1][n];
        memset(f, 0x3f, sizeof f);
        f[0][0] = passingFees[0];
        for (int i = 1; i <= maxTime; i++) {
            for (auto &e: edges) {
                int x = e[0], y = e[1], z = e[2];
                if (i >= z) {
                    f[i][y] = min(f[i][y], f[i - z][x] + passingFees[y]);
                    f[i][x] = min(f[i][x], f[i - z][y] + passingFees[x]);
                }
            }
        }
        int res = 1e9;
        for (int i = 1; i <= maxTime; i++) {
            res = min(res, f[i][n - 1]);
        }
        return res >= 1e9 ? -1 : res;
    }
};