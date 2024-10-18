#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>> &requirements) {
        const int MOD = 1e9 + 7;
        int cnt[n], m = 0;
        memset(cnt, -1, sizeof cnt);
        for (auto &req: requirements) {
            if (!req[0] && req[1]) {
                return 0;
            }
            m = max(m, req[1]);
            cnt[req[0]] = req[1];
        }
        int f[n][m + 1];
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i < n; i++) {
            int l = 0, r = m;
            if (cnt[i] >= 0) {
                l = r = cnt[i];
            }
            for (int j = l; j <= r; j++) {
                for (int x = 0; x <= min(i, j); x++) {
                    f[i][j] = (f[i][j] + f[i - 1][j - x]) % MOD;
                }
            }
        }
        return f[n - 1][cnt[n - 1]];
    }
};