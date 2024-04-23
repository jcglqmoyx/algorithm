#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        int h[n], e[n << 1], ne[n << 1], idx = 0;
        memset(h, -1, sizeof h);
        auto add = [&](int a, int b) {
            e[idx] = b, ne[idx] = h[a], h[a] = idx++;
        };
        for (auto &edge: edges) {
            add(edge[0], edge[1]);
            add(edge[1], edge[0]);
        }
        int p = 0, max_dist = -1;
        vector<int> res;
        int path[n];
        idx = 0;
        function<void(int, int, int, bool)> dfs = [&](int u, int last, int dist, bool flag) {
            if (flag) path[idx++] = u;
            if (dist > max_dist) {
                max_dist = dist;
                p = u;
                if (flag) {
                    res.clear();
                    if (idx & 1) {
                        res = {path[idx >> 1]};
                    } else {
                        res = {path[(idx >> 1) - 1], path[idx >> 1]};
                    }
                }

            }
            for (int i = h[u]; ~i; i = ne[i]) {
                if (e[i] != last) {
                    dfs(e[i], u, dist + 1, flag);
                }
            }
            if (flag) idx--;
        };
        dfs(0, -1, 0, false);
        max_dist = -1;
        dfs(p, -1, 0, true);
        return res;
    }
};