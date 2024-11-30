#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs) {
        unordered_map<int, vector<int>> g;
        unordered_map<int, int> in_degree;
        for (auto &p: pairs) {
            g[p[0]].emplace_back(p[1]);
            in_degree[p[1]]++;
        }
        int start = -1;
        for (auto &[k, v]: g) {
            if (in_degree[k] + 1 == v.size()) {
                start = k;
                break;
            }
        }
        vector<int> path;
        vector<vector<int>> res;
        auto dfs = [&](auto &&dfs, int u) -> void {
            while (!g[u].empty()) {
                int x = g[u].back();
                g[u].pop_back();
                dfs(dfs, x);
            }
            path.emplace_back(u);
        };
        if (start == -1) {
            dfs(dfs, pairs[0][0]);
        } else {
            dfs(dfs, start);
        }
        reverse(path.begin(), path.end());
        for (int i = 0; i + 1 < path.size(); i++) {
            res.push_back({path[i], path[i + 1]});
        }
        return res;
    }
};