#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        int n = static_cast<int>(edges.size());
        int h[n + 1], e[n], ne[n], d[n + 1], idx;

        memset(d, 0, sizeof d);
        for (auto &edge: edges) {
            d[edge[1]]++;
        }
        int node = -1;
        for (int i = 1; i <= n; i++) {
            if (d[i] == 2) {
                node = i;
                break;
            }
        }

        int q[n];
        int st[n + 1];
        auto add = [&](int a, int b) {
            e[idx] = b, d[b]++, ne[idx] = h[a], h[a] = idx++;
        };
        for (int i = n - 1; i >= 0; i--) {
            if (edges[i][1] != node) continue;
            idx = 0;
            memset(h, -1, sizeof h);
            memset(d, 0, sizeof d);
            memset(st, 0, sizeof st);
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    add(edges[j][0], edges[j][1]);
                }
            }
            int root = -1;
            for (int j = 1; j <= n; j++) {
                if (!d[j]) {
                    root = j;
                    break;
                }
            }
            int cnt = 0;
            int hh = 0, tt = -1;
            q[++tt] = root;
            st[root] = 1;
            while (hh <= tt) {
                int t = q[hh++];
                cnt++;
                for (int u = h[t]; ~u; u = ne[u]) {
                    int j = e[u];
                    if (!st[j]) {
                        q[++tt] = j;
                        st[j] = 1;
                    }
                }
            }
            if (cnt == n) return edges[i];
        }

        memset(st, 0, sizeof st);
        memset(h, -1, sizeof h);
        idx = 0;
        for (auto &edge: edges) {
            add(edge[1], edge[0]);
        }
        auto dfs = [&](auto &&dfs, int u) -> void {
            st[u]++;
            for (int i = h[u]; ~i; i = ne[i]) {
                int j = e[i];
                if (st[j] == 2) continue;
                dfs(dfs, j);
            }
        };
        dfs(dfs, 1);
        for (int i = n - 1; i >= 0; i--) {
            if (st[edges[i][0]] == 2 && st[edges[i][1]] == 2) {
                return edges[i];
            }
        }
        return {};
    }
};