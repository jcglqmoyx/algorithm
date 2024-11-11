#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n) {
        auto m = edges.size() * 2 + 1;
        int h[n], w[m], e[m], ne[m], idx = 0;
        memset(h, -1, sizeof h);
        auto add = [&](int a, int b, int c) {
            e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
        };
        for (auto &edge: edges) {
            add(edge[0], edge[1], edge[2] + 1);
            add(edge[1], edge[0], edge[2] + 1);
        }
        int dist[n];
        memset(dist, 0x3f, sizeof dist);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, 0);
        int res = 0;
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            if (dist[t.second] <= t.first) continue;
            dist[t.second] = t.first;
            if (t.first <= maxMoves) res++;
            for (int i = h[t.second]; ~i; i = ne[i]) {
                int j = e[i], d = w[i];
                if (dist[j] > t.first + d) {
                    q.emplace(t.first + d, j);
                }
            }
        }
        for (auto &edge: edges) {
            int x = edge[0], y = edge[1], z = edge[2];
            if (dist[x] <= maxMoves && dist[y] <= maxMoves) {
                int l = maxMoves - dist[x];
                int r = maxMoves - dist[y];
                res += min(l + r, z);
            } else if (dist[x] <= maxMoves) {
                res += maxMoves - dist[x];
            } else if (dist[y] <= maxMoves) {
                res += maxMoves - dist[y];
            }
        }
        return res;
    }
};