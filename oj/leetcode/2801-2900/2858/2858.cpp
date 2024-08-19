#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>> &edges) {
        int h[n], e[n << 1], ne[n << 1], idx = 0;
        memset(h, -1, sizeof h);
        bool pass[n << 1];
        int down[n], up[n];
        memset(down, 0, sizeof down), memset(up, 0, sizeof up);
        auto add = [&](int a, int b, bool flag) {
            e[idx] = b, pass[idx] = flag, ne[idx] = h[a], h[a] = idx++;
        };
        for (auto &edge: edges) {
            add(edge[0], edge[1], true);
            add(edge[1], edge[0], false);
        }
        auto dfs1 = [&](auto &&dfs1, int u, int p) -> int {
            for (int i = h[u]; ~i; i = ne[i]) {
                int j = e[i];
                if (j == p) continue;
                int t = dfs1(dfs1, j, u);
                down[u] += t + !pass[i];
            }
            return down[u];
        };
        dfs1(dfs1, 0, -1);
        vector<int> res(n);
        auto dfs2 = [&](auto &&dfs2, int u, int p, bool flag) -> void {
            if (p != -1) {
                up[u] = up[p] + (down[p] - down[u] - !flag) + flag;
            }
            res[u] = down[u] + up[u];
            for (int i = h[u]; ~i; i = ne[i]) {
                int j = e[i];
                if (j == p) continue;
                dfs2(dfs2, j, u, pass[i]);
            }
        };
        dfs2(dfs2, 0, -1, false);
        return res;
    }
};