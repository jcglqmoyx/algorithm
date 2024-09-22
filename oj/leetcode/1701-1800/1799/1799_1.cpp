#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y) {
    return x % y == 0 ? y : gcd(y, x % y);
}

class Solution {
public:
    int maxScore(vector<int> &nums) {
        auto n = nums.size();
        int memo[1 << n];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                memo[(1 << i) | (1 << j)] = gcd(nums[i], nums[j]);
            }
        }
        int f[1 << n];
        memset(f, 0, sizeof f);
        for (int i = 1; i * 2 <= n; i++) {
            int g[1 << n];
            memset(g, 0, sizeof g);
            for (int j = 0; j < 1 << n; j++) {
                if (__builtin_popcount(j) % 2 == 0) {
                    for (int k = j; k; k = (k - 1) & j) {
                        if (__builtin_popcount(k) == 2) {
                            g[j] = max(g[j], f[j ^ k] + i * memo[k]);
                        }
                    }
                }
            }
            memcpy(f, g, sizeof g);
        }
        return f[(1 << n) - 1];
    }
};