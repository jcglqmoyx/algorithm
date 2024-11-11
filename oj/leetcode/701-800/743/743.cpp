#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        int h[n + 1], w[12000], e[12000], ne[12000], idx = 0;
        memset(h, -1, sizeof h);
        auto add = [&](int a, int b, int c) {
            e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
        };
        for (auto &time: times) {
            add(time[0], time[1], time[2]);
        };
        int dist[n + 1];
        memset(dist, 0x3f, sizeof dist);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, k);
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            if (dist[t.second] < t.first) continue;
            dist[t.second] = t.first;
            for (int i = h[t.second]; ~i; i = ne[i]) {
                int j = e[i], d = w[i];
                if (dist[j] > t.first + d) {
                    q.emplace(t.first + d, j);
                }
            }
        }
        int res = *max_element(dist + 1, dist + n + 1);
        return res == 0x3f3f3f3f ? -1 : res;
    }
};