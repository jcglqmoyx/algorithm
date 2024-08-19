#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestPalindrome(int n, int k) {
        int m = (n + 1) / 2;
        bool vis[m + 1][k];
        memset(vis, 0, sizeof vis);
        int p10[n];
        p10[0] = 1;
        for (int i = 1; i < n; i++) {
            p10[i] = p10[i - 1] * 10 % k;
        }
        string ans(n, 0);
        auto dfs = [&](auto &&dfs, int i, int j) {
            if (i == m) {
                return j == 0;
            }
            vis[i][j] = true;
            for (int d = 9; d >= 0; d--) {
                int j2;
                if (n & 1 && i == m - 1) {
                    j2 = (j + d * p10[i]) % k;
                } else {
                    j2 = (j + d * (p10[i] + p10[n - i - 1])) % k;
                }
                if (!vis[i + 1][j2] && dfs(dfs, i + 1, j2)) {
                    ans[i] = ans[n - i - 1] = (char) (d + '0');
                    return true;
                }
            }
            return false;
        };
        dfs(dfs, 0, 0);
        return ans;
    }
};