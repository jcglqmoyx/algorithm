#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>> &edges) {
        using ll = long long;
        using pii = pair<ll, int>;
        vector<vector<pii>> g(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1], w = e[2];
            g[x].emplace_back(y, w);
            g[y].emplace_back(x, w);
        }
        vector<ll> dist1(n, 10000000000LL), dist2(n, 10000000000LL);
        dist1[0] = 0;
        dist2[n - 1] = 0;
        vector<bool> st1(n), st2(n);
        priority_queue<pii, vector<pii>, greater<>> q;
        q.emplace(0, 0);
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            if (st1[t.second]) continue;
            st1[t.second] = true;
            for (auto &ne: g[t.second]) {
                ll x = ne.first;
                int w = ne.second;
                if (dist1[x] > t.first + w) {
                    dist1[x] = t.first + w;
                    q.emplace(dist1[x], x);
                }
            }
        }
        auto m = edges.size();
        vector<bool> res(m);
        if (dist1[n - 1] == 10000000000LL) return res;
        q.emplace(0, n - 1);
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            if (st2[t.second]) continue;
            st2[t.second] = true;
            for (auto &ne: g[t.second]) {
                ll x = ne.first;
                int w = ne.second;
                if (dist2[x] > t.first + w) {
                    dist2[x] = t.first + w;
                    q.emplace(dist2[x], x);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            int x = edges[i][0], y = edges[i][1], w = edges[i][2];
            if (dist1[x] > dist1[y]) swap(x, y);
            if (dist1[x] + w + dist2[y] == dist1[n - 1]) res[i] = true;
            else res[i] = false;
        }
        return res;
    }
};