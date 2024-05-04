#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>> &roads) {
        auto m = roads.size() * 2 + 1;
        int h[n], w[m], e[m], ne[m], idx = 0;
        memset(h, -1, sizeof h);
        auto add = [&](int a, int b, int c) {
            e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
        };
        for (auto &road: roads) {
            add(road[0], road[1], road[2]);
            add(road[1], road[0], road[2]);
        }
        long long dist[n];
        memset(dist, 0x3f, sizeof dist);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
        q.emplace(0, 0);
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
        int f[n], MOD = 1e9 + 7;
        memset(f, 0, sizeof f);
        f[0] = 1;
        vector<pair<long long, int>> v(n);
        for (int i = 0; i < n; i++) v[i] = {dist[i], i};
        sort(v.begin(), v.end());
        for (auto &p: v) {
            for (int i = h[p.second]; ~i; i = ne[i]) {
                int j = e[i];
                if (dist[j] == p.first + w[i]) {
                    f[j] = (f[j] + f[p.second]) % MOD;
                }
            }
        }
        return f[n - 1];
    }
};