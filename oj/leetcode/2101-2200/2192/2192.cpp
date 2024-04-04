#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
        vector<int> d(n);
        vector<vector<int>> g(n);
        vector<vector<int>> res(n);
        vector<set<int>> ancestors(n);
        for (auto &e: edges) {
            d[e[1]]++;
            g[e[0]].emplace_back(e[1]);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (d[i] == 0) q.emplace(i);
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int ne: g[t]) {
                ancestors[ne].emplace(t);
                for (int ancestor: ancestors[t]) {
                    ancestors[ne].emplace(ancestor);
                }
                if (--d[ne] == 0) q.emplace(ne);
            }
        }
        for (int i = 0; i < n; i++) {
            res[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }
        return res;
    }
};
