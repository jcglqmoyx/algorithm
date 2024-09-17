#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target) {
        if (source == target) return 0;
        auto n = routes.size();
        int dist[n][n];
        memset(dist, 0x3f, sizeof dist);
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
            for (int x: routes[i]) {
                map[x].emplace_back(i);
            }
        }
        for (auto &[_, v]: map) {
            for (int i = 0; i < v.size(); i++) {
                for (int j = i + 1; j < v.size(); j++) {
                    dist[v[i]][v[j]] = dist[v[j]][v[i]] = 1;
                }
            }
        }
        int inf = 0x3f3f3f3f, res = inf;
        for (int u = 0; u < n; u++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][u] + dist[u][j]);
                }
            }
        }
        for (int x: map[source]) {
            for (int y: map[target]) {
                res = min(res, dist[x][y]);
            }
        }
        if (res == inf) return -1;
        return res + 1;
    }
};