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
        int f[n][m + 1], s[n][m + 1];
        memset(f, 0, sizeof f);
        memset(s, 0, sizeof s);
        f[0][0] = 1;
        fill(s[0], s[0] + m + 1, 1);
        for (int i = 1; i < n; i++) {
            int l = 0, r = m;
            if (cnt[i] >= 0) {
                l = r = cnt[i];
            }
            for (int j = l; j <= r; j++) {
                f[i][j] = s[i - 1][j];
                if (j - min(i, j)) {
                    f[i][j] = (f[i][j] - s[i - 1][j - min(i, j) - 1] + MOD) % MOD;
                }
            }
            s[i][0] = f[i][0];
            for (int j = 1; j <= m; j++) {
                s[i][j] = (f[i][j] + s[i][j - 1]) % MOD;
            }
        }
        return f[n - 1][cnt[n - 1]];
    }
};