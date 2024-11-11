#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string> &dictionary) {
        auto n = s.size();
        int tot = 1;
        for (auto &s: dictionary) tot += s.size();
        int tr[tot][26], idx = 0;
        memset(tr, 0, sizeof tr);
        bool is_end[tot];
        memset(is_end, 0, sizeof is_end);

        for (auto &w: dictionary) {
            int p = 0;
            for (int i = w.size() - 1; i >= 0; i--) {
                int u = w[i] - 'a';
                if (!tr[p][u]) tr[p][u] = ++idx;
                p = tr[p][u];
            }
            is_end[p] = true;
        }

        int f[n + 1];
        f[0] = 0;

        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1] + 1;
            int p = 0;
            for (int j = i; j; j--) {
                int u = s[j - 1] - 'a';
                if (!tr[p][u]) break;
                p = tr[p][u];
                if (is_end[p]) f[i] = min(f[i], f[j - 1]);
            }
        }
        return f[n];
    }
};