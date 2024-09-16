#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        vector<vector<int>> table = {
                {4, 5, 7,  8,  9},
                {4, 6, 7,  8},
                {4, 5, 8,  9,  11},
                {5, 9, 10, 11},
                {0, 1, 2,  10, 11},
                {0, 2, 3,  10},
                {1, 8, 9,  11},
                {0, 1, 9,  10, 11},
                {0, 1, 2,  6},
                {0, 2, 3,  6,  7},
                {3, 4, 5,  7},
                {2, 3, 4,  6,  7},
        };
        int f[12], m = 1e9 + 7;
        fill(f, f + 12, 1);
        for (int i = 1; i < n; i++) {
            int g[12]{};
            for (int j = 0; j < 12; j++) {
                for (int k: table[j]) {
                    g[j] = g[j] + f[k];
                    if (g[j] > m) {
                        g[j] -= m;
                    }
                }
            }
            memcpy(f, g, sizeof g);
        }
        int res = 0;
        for (int x: f) {
            res += x;
            if (res > m) {
                res -= m;
            }
        }
        return res;
    }
};