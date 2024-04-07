#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> cost, ids;
    vector<vector<pair<int, int>>> g;

    void dfs(int u, int id) {
        ids[u] = id;
        for (auto &ne: g[u]) {
            cost[id] &= ne.second;
            if (ids[ne.first] == -1) {
                dfs(ne.first, id);
            }
        }
    }

public:
    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query) {
        cost.resize(n, INT32_MAX), ids.resize(n, -1), g.resize(n);
        for (auto &e: edges) {
            g[e[0]].emplace_back(e[1], e[2]);
            g[e[1]].emplace_back(e[0], e[2]);
        }
        for (int i = 0, id = 0; i < n; i++) {
            if (ids[i] == -1) {
                dfs(i, id);
                id++;
            }
        }
        vector<int> res;
        res.reserve(query.size());
        for (auto &q: query) {
            if (q[0] == q[1]) res.push_back(0);
            else if (ids[q[0]] != ids[q[1]]) res.emplace_back(-1);
            else res.emplace_back(cost[ids[q[0]]]);
        }
        return res;
    }
};
