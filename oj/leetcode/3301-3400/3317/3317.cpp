#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfWays(int n, int x, int y) {
        int m = 1e9 + 7;
        long long f[n + 1][x + 1];
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int j = 1; j <= x; j++) {
            for (int i = 1; i <= n; i++) {
                f[i][j] = (f[i - 1][j] * j + f[i - 1][j - 1] * (x - j + 1));
                f[i][j] %= m;
            }
        }
        long long res = 0, p = 1;
        for (int j = 1; j <= x; j++) {
            p = p * y % m;
            res = (res + f[n][j] * p) % m;
        }
        return res;
    }
};