#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear) {
        size_t m = edges.size();
        int h[n], e[m * 2 + 1], ne[m * 2 + 1], w[m * 2 + 1], idx = 0;
        memset(h, -1, sizeof h);

        auto add = [&](int a, int b, int c) {
            e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
        };

        for (auto &edge: edges) {
            int a = edge[0], b = edge[1], c = edge[2];
            add(a, b, c), add(b, a, c);
        }

        vector<int> res(n, -1);
        res[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, 0);
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            if (res[t.second] < t.first) continue;
            for (auto i = h[t.second]; ~i; i = ne[i]) {
                if ((res[e[i]] == -1 || res[e[i]] > t.first + w[i]) && disappear[e[i]] > t.first + w[i]) {
                    res[e[i]] = t.first + w[i];
                    q.emplace(res[e[i]], e[i]);
                }
            }
        }
        return res;
    }
};