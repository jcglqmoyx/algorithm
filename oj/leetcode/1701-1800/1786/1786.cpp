#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>> &edges) {
        auto m = edges.size() * 2;
        int h[n + 1], w[m], e[m], ne[m], idx = 0;
        memset(h, -1, sizeof h);
        auto add = [&](int a, int b, int c) {
            e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
        };
        for (auto &e: edges) {
            int x = e[0], y = e[1], z = e[2];
            add(x, y, z);
            add(y, x, z);
        }
        int dist[n + 1];
        int f[n + 1], MOD = 1e9 + 7;
        fill(dist, dist + n + 1, 2e9);
        memset(f, 0, sizeof f);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, n);
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            if (dist[t.second] <= t.first) continue;
            dist[t.second] = t.first;
            for (int i = h[t.second]; ~i; i = ne[i]) {
                int j = e[i];
                if (dist[j] > t.first + w[i]) {
                    q.emplace(t.first + w[i], j);
                }
            }
        }
        vector<pair<int, int>> v(n);
        for (int i = 1; i <= n; i++) {
            v[i - 1] = {dist[i], i};
        }
        sort(v.begin(), v.end());
        f[n] = 1;
        for (auto &p: v) {
            for (int i = h[p.second]; ~i; i = ne[i]) {
                if (dist[e[i]] > dist[p.second]) {
                    f[e[i]] = (f[e[i]] + f[p.second]) % MOD;
                }
            }
        }
        return f[1];
    }
};