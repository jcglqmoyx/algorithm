#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int> &piles) {
        auto n = piles.size();
        int f[n + 2][n + 1], s[n + 1];
        memset(f, 0, sizeof f);
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + piles[i - 1];
        }
        for (int i = n; i; i--) {
            for (int j = 1; j <= n / 2 + 1; j++) {
                for (int k = 1; i + k - 1 <= n && k <= j * 2; k++) {
                    f[i][j] = max(f[i][j], s[n] - s[i - 1] - f[i + k][max(k, j)]);
                }
            }
        }
        return f[1][1];
    }
};