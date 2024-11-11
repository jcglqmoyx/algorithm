#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string> &words) {
        int tot = 0;
        for (auto &s: words) tot += s.size();
        int son[tot + 1][26], cnt[tot + 1], idx = 0;
        memset(son, 0, sizeof son), memset(cnt, 0, sizeof cnt);
        long long res = 0;
        for (auto &s: words) {
            int n = s.size();

            int z[n];
            memset(z, 0, sizeof z);
            for (int l = 0, r = 0, i = 0; i < n; i++) {
                if (i <= r) z[i] = min(z[i - l], r - i + 1);
                while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                    l = i;
                    r = i + z[i];
                    z[i]++;
                }
            }
            z[0] = n;

            int p = 0;
            for (int i = 0; i < n; i++) {
                int u = s[i] - 'a';
                if (!son[p][u]) son[p][u] = ++idx;
                p = son[p][u];
                if (z[n - i - 1] == i + 1) res += cnt[p];
            }
            cnt[p]++;
        }
        return res;
    }
};