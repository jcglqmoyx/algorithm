#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canDistribute(vector<int> &nums, vector<int> &quantity) {
        int mx = 0;
        for (int x: nums) {
            mx = max(mx, x);
        }
        int cnt[mx + 1];
        memset(cnt, 0, sizeof cnt);
        for (int x: nums) cnt[x]++;
        int n = 0;
        for (int i = 1; i <= mx; i++) {
            if (cnt[i]) n++;
        }
        for (int i = 1, j = 1; i <= mx; i++) {
            if (cnt[i]) {
                cnt[j++] = cnt[i];
            }
        }
        auto m = quantity.size();
        int s[1 << m];
        memset(s, 0, sizeof s);
        for (int i = 1; i < 1 << m; i++) {
            int j = i & -i;
            s[i] = s[i ^ j] + quantity[__builtin_ctz(j)];
        }
        bool f[2][1 << m];
        memset(f, 0, sizeof f);
        f[0][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 1 << m; j++) {
                f[i & 1][j] |= f[i & 1 ^ 1][j];
                for (int k = j; k; k = (k - 1) & j) {
                    if (cnt[i] >= s[k]) {
                        f[i & 1][j] |= f[i & 1 ^ 1][j ^ k];
                    }
                }
            }
        }
        return f[n & 1][(1 << m) - 1];
    }
};