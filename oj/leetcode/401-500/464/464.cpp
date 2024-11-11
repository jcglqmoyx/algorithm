#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) return false;
        int f[1 << maxChoosableInteger];
        memset(f, -1, sizeof f);
        auto dp = [&](auto &&dp, int mask, int s) -> bool {
            if (f[mask] != -1) return f[mask];
            for (int i = 0; i < maxChoosableInteger; i++) {
                if (mask >> i & 1) continue;
                if (s + i + 1 >= desiredTotal || !dp(dp, mask | 1 << i, s + i + 1)) return f[mask] = true;
            }
            return f[mask] = false;
        };
        return dp(dp, 0, 0);
    }
};