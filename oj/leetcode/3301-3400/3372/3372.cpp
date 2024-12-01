#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k) {
        int n = static_cast<int>(edges1.size()) + 1, m = static_cast<int>(edges2.size()) + 1;
        vector<int> res(n, 1);
        if (!k) {
            return res;
        }

        vector<vector<int>> g1(n), g2(m);
        for (auto &e: edges1) {
            g1[e[0]].emplace_back(e[1]);
            g1[e[1]].emplace_back(e[0]);
        }
        for (auto &e: edges2) {
            g2[e[0]].emplace_back(e[1]);
            g2[e[1]].emplace_back(e[0]);
        }
        auto dfs = [](auto &&dfs, vector<vector<int>> &g, int u, int p, int k) -> int {
            if (k < 0) return 0;
            int cnt = 1;
            for (int x: g[u]) {
                if (x != p) {
                    cnt += dfs(dfs, g, x, u, k - 1);
                }
            }
            return cnt;
        };
        int cnt2 = 0;
        for (int j = 0; j < m; j++) {
            cnt2 = max(cnt2, dfs(dfs, g2, j, -1, k - 1));
        }
        for (int i = 0; i < n; i++) {
            res[i] = dfs(dfs, g1, i, -1, k) + cnt2;
        }
        return res;
    }
};