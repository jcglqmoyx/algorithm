#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTimeRequired(vector<int> &jobs, int k) {
        auto n = jobs.size();
        int s[1 << n], f[1 << n];
        s[0] = 0, k--;
        for (int i = 1; i < 1 << n; i++) {
            f[i] = s[i] = s[i ^ (i & -i)] + jobs[__builtin_ctz(i & -i)];
        }
        while (k--) {
            int g[1 << n];
            memset(g, 0x3f, sizeof g);
            for (int j = 1; j < 1 << n; j++) {
                for (int u = j; u; u = (u - 1) & j) {
                    g[j] = min(g[j], max(f[u], s[j ^ u]));
                }
            }
            memcpy(f, g, sizeof g);
        }
        return f[(1 << n) - 1];
    }
};