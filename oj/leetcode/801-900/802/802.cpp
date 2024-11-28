#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int n = static_cast<int>(graph.size());
        int8_t memo[n];
        memset(memo, -1, sizeof memo);
        int m = 0;
        for (auto &ad: graph) {
            m += static_cast<int>(ad.size());
        }
        int h[n], e[m], ne[m], idx = 0;
        int d[n];
        memset(h, -1, sizeof h);
        memset(d, 0, sizeof d);
        auto add = [&](int a, int b) {
            e[idx] = b, ne[idx] = h[a], h[a] = idx++;
            d[a]++;
        };
        for (int i = 0; i < n; i++) {
            for (int x: graph[i]) {
                add(i, x);
            }
        }
        auto dfs = [&](auto &&dfs, int u) {
            if (memo[u] != -1) {
                return memo[u];
            }
            if (d[u] == 0) {
                memo[u] = 1;
                return memo[u];
            }
            memo[u] = 2;
            for (int i = h[u]; ~i; i = ne[i]) {
                auto t = dfs(dfs, e[i]);
                if (t == 0 || memo[e[i]] == 2) {
                    memo[u] = 0;
                    return memo[u];
                }
            }
            memo[u] = 1;
            return memo[u];
        };
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (dfs(dfs, i)) {
                res.emplace_back(i);
            }
        }
        return res;
    }
};