#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int> &start, vector<int> &target, vector<vector<int>> &specialRoads) {
        using LL = long long;
        const int N = 2e5;
        LL src = start[0] * 1LL * N + start[1], dest = target[0] * 1LL * N + target[1];
        unordered_map<LL, vector<pair<LL, int>>> g;
        unordered_map<LL, int> dist;

        auto add = [&](vector<int> &a, vector<int> &b, int cost) {
            g[a[0] * 1LL * N + a[1]].emplace_back(b[0] * 1LL * N + b[1],
                                                  min(cost, abs(a[0] - b[0]) + abs(a[1] - b[1])));
        };

        add(start, target, N);
        for (int i = 0; i < specialRoads.size(); i++) {
            vector<int> pa = {specialRoads[i][0], specialRoads[i][1]};
            vector<int> pb = {specialRoads[i][2], specialRoads[i][3]};
            add(start, pa, N);
            add(pb, target, N);
            add(pa, pb, specialRoads[i][4]);
            for (int j = 0; j < specialRoads.size(); j++) {
                if (j == i) continue;
                vector<int> ppa = {specialRoads[j][0], specialRoads[j][1]};
                vector<int> ppb = {specialRoads[j][2], specialRoads[j][3]};
                add(pa, ppa, N);
                add(pb, ppa, N);
            }
        }
        priority_queue<pair<int, LL>, vector<pair<int, LL>>, greater<>> q;
        q.emplace(0, src);
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            if (dist.contains(t.second) && dist[t.second] <= t.first) continue;
            dist[t.second] = t.first;
            for (auto &ne: g[t.second]) {
                if (!dist.contains(ne.first) || dist[ne.first] > t.first + ne.second) {
                    q.emplace(t.first + ne.second, ne.first);
                }
            }
        }
        return dist[dest];
    }
};