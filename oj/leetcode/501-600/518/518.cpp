#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>&coins) {
        int f[amount + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int c: coins) {
            for (int i = c; i <= amount; i++) {
                f[i] += f[i - c];
            }
        }
        return f[amount];
    }
};
