#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>&coins, int amount) {
        int f[amount + 1];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int x: coins) {
            for (int i = x; i <= amount; i++) {
                f[i] = min(f[i], f[i - x] + 1);
            }
        }
        return f[amount] == 0x3f3f3f3f ? -1 : f[amount];
    }
};
