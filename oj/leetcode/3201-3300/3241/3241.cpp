#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> timeTaken(vector<vector<int>> &edges) {
        auto n = edges.size() + 1;
        int h[n], e[n << 1], ne[n << 1], idx = 0;
        memset(h, -1, sizeof h);
        int down1[n], idx1[n], down2[n], up[n];
        memset(down1, 0, sizeof down1);
        memset(down2, 0, sizeof down2);
        memset(idx1, -1, sizeof idx1);
        memset(up, 0, sizeof up);

        auto add = [&](int a, int b) {
            e[idx] = b, ne[idx] = h[a], h[a] = idx++;
        };
        for (auto &edge: edges) {
            add(edge[0], edge[1]);
            add(edge[1], edge[0]);
        }
        auto dfs1 = [&](auto &&dfs1, int u, int p) -> int {
            for (int i = h[u]; ~i; i = ne[i]) {
                int j = e[i];
                if (j == p) continue;
                int t = dfs1(dfs1, j, u) + (1 + !(j & 1));
                if (t > down1[u]) {
                    down2[u] = down1[u];
                    down1[u] = t;
                    idx1[u] = j;
                } else if (t > down2[u]) {
                    down2[u] = t;
                }
            }
            return down1[u];
        };
        dfs1(dfs1, 0, -1);
        vector<int> res(n);
        auto dfs2 = [&](auto &&dfs2, int u, int p) -> void {
            if (p != -1) {
                up[u] = up[p];
                if (idx1[p] == u) up[u] = max(up[u], down2[p]);
                else up[u] = max(up[u], down1[p]);
                up[u] += 1 + !(p & 1);
            }
            res[u] = max(down1[u], up[u]);
            for (int i = h[u]; ~i; i = ne[i]) {
                int j = e[i];
                if (j == p) continue;
                dfs2(dfs2, j, u);
            }
        };
        dfs2(dfs2, 0, -1);
        return res;
    }
};