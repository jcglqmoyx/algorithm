#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node) {
        auto m = edges.size();
        int h[n], e[m * 2], ne[m * 2], idx = 0;
        double w[m * 2];
        memset(h, -1, sizeof h);
        auto add = [&](int a, int b, double c) {
            e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
        };
        for (int i = 0; i < m; i++) {
            add(edges[i][0], edges[i][1], succProb[i]);
            add(edges[i][1], edges[i][0], succProb[i]);
        }
        double dist[n];
        memset(dist, 0, sizeof dist);
        priority_queue<pair<double, int>> q;
        q.emplace(1, start_node);
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            if (dist[t.second] >= t.first) continue;
            dist[t.second] = t.first;
            for (int i = h[t.second]; ~i; i = ne[i]) {
                int j = e[i];
                if (dist[j] < t.first * w[i]) {
                    q.emplace(t.first * w[i], j);
                }
            }
        }
        return dist[end_node];
    }
};