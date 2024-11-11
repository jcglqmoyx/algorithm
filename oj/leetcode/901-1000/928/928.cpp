#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial) {
        auto n = graph.size();
        bool st[n], vis[n];
        memset(st, 0, sizeof st);
        memset(vis, 0, sizeof vis);
        for (int x: initial) st[x] = true;
        int cnt[n];
        memset(cnt, 0, sizeof cnt);
        function<void(int, int &, int &)> dfs = [&](int u, int &size, int &node_id) {
            size++;
            vis[u] = true;
            for (int i = 0; i < n; i++) {
                if (graph[u][i]) {
                    if (st[i]) {
                        if (node_id == -1) {
                            node_id = i;
                        } else if (node_id != i) {
                            node_id = -2;
                        }
                    } else {
                        if (!vis[i]) {
                            dfs(i, size, node_id);
                        }
                    }
                }
            }
        };
        for (int i = 0; i < n; i++) {
            if (st[i] || vis[i]) continue;
            int size = 0, node_id = -1;
            dfs(i, size, node_id);
            if (node_id >= 0) {
                cnt[node_id] += size;
            }
        }
        int res = -1, m = 0;
        for (int idx = 0, i = 0; i < n; i++) {
            if (st[i]) initial[idx++] = i;
        }
        for (int x: initial) {
            if (res == -1 || cnt[x] > m) {
                m = cnt[x];
                res = x;
            }
        }
        return res;
    }
};