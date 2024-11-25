#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximizeSumOfWeights(vector<vector<int>> &edges, int k) {
        using LL = long long;
        int n = static_cast<int>(edges.size()) + 1;
        int h[n], w[n * 2], e[n * 2], ne[n * 2], idx = 0;
        memset(h, -1, sizeof h);
        auto add = [&](int a, int b, int dist) {
            e[idx] = b, w[idx] = dist, ne[idx] = h[a], h[a] = idx++;
        };
        for (auto &edge: edges) {
            int x = edge[0], y = edge[1], z = edge[2];
            add(x, y, z);
            add(y, x, z);
        }
        auto dfs = [&](auto &&dfs, int u, int p) -> pair<LL, LL> {
            pair<LL, LL> res;
            vector<LL> v;
            for (int i = h[u]; ~i; i = ne[i]) {
                if (e[i] != p) {
                    auto t = dfs(dfs, e[i], u);
                    res.first += t.first;
                    LL dt = w[i] - (t.first - t.second);
                    if (dt > 0) {
                        v.emplace_back(dt);
                    }
                }
            }
            sort(v.begin(), v.end(), greater<>());
            res.first += accumulate(v.begin(), v.begin() + min(static_cast<int>(v.size()), k), 0LL);
            res.second = res.first;
            if (v.size() >= k) res.second -= v[k - 1];
            return res;
        };
        return dfs(dfs, 0, -1).first;
    }
};