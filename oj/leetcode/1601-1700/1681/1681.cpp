#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumIncompatibility(vector<int> &nums, int k) {
        auto n = nums.size();
        if (n == 1) return 0;
        int sub = n / k;
        auto check = [&](int mask) {
            if (__builtin_popcount(mask) != sub) return -1;
            int used = 0;
            int mn = n, mx = 1;
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) {
                    if (used >> nums[i] & 1) return -1;
                    used |= 1 << nums[i];
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                }
            }
            return mx - mn;
        };
        int valid[1 << n];
        for (int i = 0; i < 1 << n; i++) {
            valid[i] = check(i);
        }
        int f[1 << n], inf = 0x3f3f3f3f;
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 1; i < 1 << n; i++) {
            if (__builtin_popcount(i) % sub == 0) {
                for (int j = i; j; j = (j - 1) & i) {
                    if (valid[j] != -1) {
                        f[i] = min(f[i], f[i ^ j] + valid[j]);
                    }
                }
            }
        }
        int res = f[(1 << n) - 1];
        if (res >= inf) res = -1;
        return res;
    }
};