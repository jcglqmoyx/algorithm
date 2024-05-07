#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 100010;

int h[N], w[N], e[N], ne[N], idx;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

vector<LL> dijkstra(int n, int src) {
    vector<LL> dist(n, 1e10);
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<>> q;
    q.emplace(0, src);
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        if (dist[t.second] <= t.first) continue;
        dist[t.second] = t.first;
        for (int i = h[t.second]; ~i; i = ne[i]) {
            int j = e[i], d = w[i];
            if (dist[j] > t.first + d) {
                q.emplace(t.first + d, j);
            }
        }
    }
    return dist;
}

class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2, int dest) {
        memset(h, -1, sizeof(int) * n), idx = 0;
        for (auto &edge: edges) {
            add(edge[0], edge[1], edge[2]);
        }
        auto d1 = dijkstra(n, src1);
        if (d1[dest] >= 1e10) return -1;
        auto d2 = dijkstra(n, src2);
        if (d2[dest] >= 1e10) return -1;
        memset(h, -1, sizeof(int) * n), idx = 0;
        for (auto &edge: edges) {
            add(edge[1], edge[0], edge[2]);
        }
        auto d3 = dijkstra(n, dest);
        LL res = d1[dest] + d2[dest];
        for (int i = 0; i < n; i++) {
            res = min(res, d1[i] + d2[i] + d3[i]);
        }
        return res;
    }
};