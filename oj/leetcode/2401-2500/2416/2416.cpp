#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sumPrefixScores(vector<string> &words) {
        int n = words.size(), tot = 1;
        for (auto &w: words) tot += w.size();
        vector<vector<int>> tr(tot, vector<int>(26));
        int cnt[tot], idx = 0;
        memset(cnt, 0, sizeof cnt);
        for (auto &s: words) {
            int p = 0;
            for (char c: s) {
                int u = c - 'a';
                if (!tr[p][u]) tr[p][u] = ++idx;
                p = tr[p][u];
                cnt[p]++;
            }
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int p = 0;
            for (char c: words[i]) {
                int u = c - 'a';
                if (!tr[p][u]) break;
                p = tr[p][u];
                res[i] += cnt[p];
            }
        }
        return res;
    }
};