#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
        auto m = queries.size();
        set<pair<int, int>> s;
        s.emplace(-1, -1);
        s.emplace(1e9, 1e9);
        vector<int> res(m);
        for (int dist = n - 1, i = 0; i < m; i++) {
            int u = queries[i][0], v = queries[i][1];
            auto it = s.lower_bound({u, -1});
            if (it->first == u && it->second >= v) {
                res[i] = dist;
                continue;
            }
            it--;
            if (it->first <= u && it->second >= v) {
                res[i] = dist;
                continue;
            }
            it++;
            dist -= v - u - 1;
            while (it->second <= v) {
                dist += it->second - it->first - 1;
                auto p = it;
                it++;
                s.erase(p);
            }
            res[i] = dist;
            s.emplace(u, v);
        }
        return res;
    }
};