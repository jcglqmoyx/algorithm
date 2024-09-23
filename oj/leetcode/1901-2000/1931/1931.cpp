#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int colorTheGrid(int m, int n) {
        int tot = 1, MOD = 1e9 + 7;
        for (int i = 0; i < m; i++) tot *= 3;
        int f[tot];
        memset(f, 0, sizeof f);
        vector<int> v[tot];
        for (int i = 0; i < tot; i++) {
            int mask = i;
            for (int prev = -1, j = 0; j < m; j++) {
                int t = mask % 3;
                if (t == prev) {
                    v[i].clear();
                    break;
                }
                v[i].emplace_back(t);
                mask /= 3;
                prev = t;
            }
            if (!v[i].empty()) f[i] = 1;
        }
        for (int i = 1; i < n; i++) {
            int g[tot];
            memset(g, 0, sizeof g);
            for (int cur = 0; cur < tot; cur++) {
                if (v[cur].empty()) continue;
                for (int last = 0; last < tot; last++) {
                    if (v[last].empty()) continue;
                    bool ok = true;
                    for (int j = 0; j < m; j++) {
                        if (v[cur][j] == v[last][j]) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) g[cur] = (g[cur] + f[last]) % MOD;
                }
            }
            memcpy(f, g, sizeof g);
        }
        int res = 0;
        for (int i = 0; i < tot; i++) {
            res = (res + f[i]) % MOD;
        }
        return res;
    }
};