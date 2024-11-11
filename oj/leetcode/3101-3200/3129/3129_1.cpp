#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;

        int f[zero + 1][one + 1][2];
        memset(f, 0, sizeof f);

        for (int i = 0; i <= min(limit, zero); i++) f[i][0][0] = 1;
        for (int j = 0; j <= min(limit, one); j++) f[0][j][1] = 1;

        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                for (int k = 1; k <= min(limit, i); k++) {
                    f[i][j][0] = (f[i][j][0] + f[i - k][j][1]) % MOD;
                }
                for (int k = 1; k <= min(limit, j); k++) {
                    f[i][j][1] = (f[i][j][1] + f[i][j - k][0]) % MOD;
                }
            }
        }
        return (f[zero][one][0] + f[zero][one][1]) % MOD;
    }
};