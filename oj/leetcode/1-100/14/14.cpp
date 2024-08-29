#include <bits/stdc++.h>

using namespace std;

const int N = 40010;

int tr[N][26], idx;
int cnt[N];

void insert(string &s) {
    int p = 0;
    for (auto &c: s) {
        int u = c - 'a';
        if (!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
        cnt[p]++;
    }
}

class Solution {

public:
    string longestCommonPrefix(vector<string> &strs) {
        int tot = 1;
        for (auto &s: strs) {
            tot += s.size();
        }
        for (int i = 0; i < tot; i++) {
            memset(tr[i], 0, sizeof tr[i]);
        }
        idx = 0;
        memset(cnt, 0, sizeof(int) * tot);
        for (auto &s: strs) {
            insert(s);
        }
        int mx = 0;
        for (int p = 0, i = 0; i < strs[0].size(); i++) {
            int u = strs[0][i] - 'a';
            if (tr[p][u]) {
                p = tr[p][u];
                if (cnt[p] == strs.size()) {
                    mx = i + 1;
                }
            } else {
                break;
            }
        }
        return mx ? strs[0].substr(0, mx) : "";
    }
};