#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>> &requirements) {
        const int MOD = 1e9 + 7;
        int cnt[n + 1], m = 0;
        memset(cnt, -1, sizeof cnt);
        for (auto &req: requirements) {
            if (!req[0] && req[1]) {
                return 0;
            }
            m = max(m, req[1]);
            cnt[req[0]] = req[1];
        }
        int f[m + 1], s[m + 1];
        memset(s, 0, sizeof s);
        fill(s, s + m + 1, 1);
        for (int i = 1; i < n; i++) {
            memset(f, 0, sizeof f);
            int t[m + 1];
            memset(t, 0, sizeof t);
            int l = 0, r = m;
            if (cnt[i] >= 0) {
                l = r = cnt[i];
            }
            for (int j = l; j <= r; j++) {
                f[j] = s[j];
                if (j - min(i, j)) {
                    f[j] = (f[j] - s[j - min(i, j) - 1] + MOD) % MOD;
                }
            }
            t[0] = f[0];
            for (int j = 1; j <= m; j++) {
                t[j] = (f[j] + t[j - 1]) % MOD;
            }
            memcpy(s, t, sizeof t);
        }
        return f[cnt[n - 1]];
    }
};