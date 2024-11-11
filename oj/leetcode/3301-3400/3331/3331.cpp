#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int> &parent, string s) {
        auto n = parent.size();
        int h[n], e[n * 2], ne[n * 2], idx;
        bool valid[n * 2];
        memset(h, -1, sizeof h);
        memset(valid, false, sizeof valid);
        auto add = [&](int a, int b) {
            e[idx] = b, valid[idx] = true, ne[idx] = h[a], h[a] = idx++;
        };
        for (int i = 1; i < n; i++) {
            add(parent[i], i);
        }
        int anc[26]{};
        memset(anc, -1, sizeof anc);
        auto dfs1 = [&](auto &&dfs1, int u) -> void {
            int old = anc[s[u] - 'a'];
            anc[s[u] - 'a'] = u;
            for (int i = h[u]; ~i; i = ne[i]) {
                int j = e[i];
                int c = s[j] - 'a';
                if (anc[c] != -1) {
                    add(anc[c], j);
                    valid[i] = false;
                }
                dfs1(dfs1, j);
            }
            anc[s[u] - 'a'] = old;
        };
        dfs1(dfs1, 0);
        vector<int> res(n);
        auto dfs2 = [&](auto &&dfs2, int u) -> int {
            res[u] = 1;
            for (int i = h[u]; ~i; i = ne[i]) {
                int j = e[i];
                if (valid[i]) {
                    res[u] += dfs2(dfs2, j);
                }
            }
            return res[u];
        };
        dfs2(dfs2, 0);
        return res;
    }
};