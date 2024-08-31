#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        auto n = s.size(), m = p.size();
        bool f[n + 1][m + 1];
        memset(f, 0, sizeof f);
        f[0][0] = true;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (i) {
                        for (int k = i; k && !(p[j - 2] != '.' && s[k - 1] != p[j - 2]); k--) {
                            f[i][j] |= f[k - 1][j - 2];
                        }
                    }
                } else if (i && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) {
                    f[i][j] |= f[i - 1][j - 1];
                }
            }
        }
        return f[n][m];
    }
};