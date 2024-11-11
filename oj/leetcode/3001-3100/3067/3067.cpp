#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> g(n);
        for (auto &e: edges) {
            g[e[0]].emplace_back(e[1], e[2]);
            g[e[1]].emplace_back(e[0], e[2]);
        }
        int cnt = 0;
        function<void(int, int, int)> dfs = [&](int u, int p, int s) {
            if (s % signalSpeed == 0) cnt++;
            for (auto &ne: g[u]) {
                if (ne.first == p) continue;
                dfs(ne.first, u, s + ne.second);
            }
        };
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            for (int t = 0, j = 0; j < g[i].size(); j++) {
                cnt = 0;
                dfs(g[i][j].first, i, g[i][j].second);
                res[i] += t * cnt;
                t += cnt;
            }
        }
        return res;
    }
};