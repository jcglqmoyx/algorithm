#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numWays(vector<string> &words, string target) {
        const int MOD = 1e9 + 7;
        auto n = words[0].size(), m = target.size();
        int s[n + 1][26];
        memset(s[0], 0, sizeof s[0]);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 26; j++) {
                s[i][j] = s[i - 1][j];
            }
            for (int u = 0; u < words.size(); u++) {
                s[i][words[u][i - 1] - 'a']++;
            }
        }

        int f[m];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++) {
            for (int j = m - 1; ~j; j--) {
                int u = target[j] - 'a';
                int cnt = s[i][u] - s[i - 1][u];
                if (cnt) {
                    if (j) f[j] = (f[j] + (long long) f[j - 1] * cnt) % MOD;
                    else f[j] = (f[j] + cnt) % MOD;
                }
            }
        }
        return f[m - 1];
    }
};