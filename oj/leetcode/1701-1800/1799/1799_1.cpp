#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y) {
    return x % y == 0 ? y : gcd(y, x % y);
}

class Solution {
public:
    int maxScore(vector<int> &nums) {
        auto n = nums.size();
        int memo[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                memo[i][j] = gcd(nums[i], nums[j]);
            }
        }
        int f[1 << n];
        memset(f, 0, sizeof f);
        for (int i = 0; i < 1 << n; i++) {
            int cnt = __builtin_popcount(i);
            if (cnt & 1) continue;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    for (int k = j + 1; k < n; k++) {
                        if (i >> k & 1) {
                            f[i] = max(f[i], f[i ^ (1 << j) ^ (1 << k)] + cnt / 2 * memo[j][k]);
                        }
                    }
                }
            }
        }
        return f[(1 << n) - 1];
    }
};