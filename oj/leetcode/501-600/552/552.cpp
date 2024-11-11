#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9 + 7;
        long long f[2][3];
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            long long g[2][3];
            g[0][0] = (f[0][0] + f[0][1] + f[0][2]) % MOD;
            g[0][1] = f[0][0];
            g[0][2] = f[0][1];
            g[1][0] = (f[1][0] + f[1][1] + f[1][2] + f[0][0] + f[0][1] + f[0][2]) % MOD;
            g[1][1] = f[1][0];
            g[1][2] = f[1][1];
            memcpy(f, g, sizeof g);
        }
        return (int) ((f[0][0] + f[0][1] + f[0][2] + f[1][0] + f[1][1] + f[1][2] + MOD * 6LL) % MOD);
    }
};