#include <bits/stdc++.h>

using namespace std;

int f[1005][1005][2];

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;

        for (int i = 1; i <= zero; i++) f[i][0][0] = i <= limit;
        for (int j = 1; j <= one; j++) f[0][j][1] = j <= limit;

        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1]) % MOD;
                if (i > limit) f[i][j][0] = (f[i][j][0] - f[i - (limit + 1)][j][1] + MOD) % MOD;

                f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1]) % MOD;
                if (j > limit) f[i][j][1] = (f[i][j][1] - f[i][j - (limit + 1)][0] + MOD) % MOD;
            }
        }
        return (f[zero][one][0] + f[zero][one][1]) % MOD;
    }
};