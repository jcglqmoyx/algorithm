#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get(char c) {
        if (c == 'F') return 0;
        if (c == 'W') return 1;
        return 2;
    }

public:
    int countWinningSequences(string s) {
        auto n = s.size();
        if (n == 1) return 1;
        int mod = 1e9 + 7;

        // f[i][j]: i: win - lose, j: choice
        int f[n * 4][3], offset = n * 2;
        memset(f, 0, sizeof f);
        if (s[0] == 'F') {
            f[1 + offset][1] = 1;
            f[0 + offset][0] = 1;
            f[-1 + offset][2] = 1;
        } else if (s[0] == 'W') {
            f[1 + offset][2] = 1;
            f[0 + offset][1] = 1;
            f[-1 + offset][0] = 1;
        } else if (s[0] == 'E') {
            f[1 + offset][0] = 1;
            f[0 + offset][2] = 1;
            f[-1 + offset][1] = 1;
        }
        for (int i = 2; i <= n; i++) {
            int g[n * 4][3];
            memset(g, 0, sizeof g);
            auto c = s[i - 1];
            for (int j = -i; j <= i; j++) {
                if (get(c) == 0) g[j + offset][0] = (f[j + offset][1] + f[j + offset][2]) % mod;
                else if (get(c) == 1) g[j + offset][0] = (f[j + 1 + offset][1] + f[j + 1 + offset][2]) % mod;
                else if (get(c) == 2) g[j + offset][0] = (f[j - 1 + offset][1] + f[j - 1 + offset][2]) % mod;

                if (get(c) == 0) g[j + offset][1] = (f[j - 1 + offset][0] + f[j - 1 + offset][2]) % mod;
                else if (get(c) == 1) g[j + offset][1] = (f[j + offset][0] + f[j + offset][2]) % mod;
                else if (get(c) == 2) g[j + offset][1] = (f[j + 1 + offset][0] + f[j + 1 + offset][2]) % mod;

                if (get(c) == 0) g[j + offset][2] = (f[j + 1 + offset][0] + f[j + 1 + offset][1]) % mod;
                else if (get(c) == 1) g[j + offset][2] = (f[j - 1 + offset][0] + f[j - 1 + offset][1]) % mod;
                else if (get(c) == 2) g[j + offset][2] = (f[j + offset][0] + f[j + offset][1]) % mod;
            }
            memcpy(f, g, sizeof g);
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                res = (res + f[i + offset][j]) % mod;
            }
        }
        return res;
    }
};