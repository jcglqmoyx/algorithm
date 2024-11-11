#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>> &relations, int k) {
        int pre[n];
        memset(pre, 0, sizeof pre);
        for (auto &relation: relations) {
            pre[relation[1] - 1] |= 1 << (relation[0] - 1);
        }
        int all_pre[1 << n];
        memset(all_pre, 0, sizeof all_pre);
        for (int i = 1; i < 1 << n; i++) {
            int lb = i & -i;
            all_pre[i] = all_pre[i ^ lb] | pre[__builtin_ctz(lb)];
        }
        int f[1 << n], inf = 0x3f3f3f3f;
        memset(f, -1, sizeof f);
        f[0] = 0;
        auto dp = [&](auto &&dp, int mask) {
            if (f[mask] != -1) return f[mask];
            f[mask] = inf;
            for (int sub = mask; sub; sub = (sub - 1) & mask) {
                if (__builtin_popcount(sub) > k) continue;
                if (!(all_pre[sub] & mask)) f[mask] = min(f[mask], dp(dp, mask ^ sub) + 1);
            }
            return f[mask];
        };
        return dp(dp, (1 << n) - 1);
    }
};