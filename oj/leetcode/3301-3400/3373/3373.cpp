#include <bits/stdc++.h>

using namespace std;

pair<int, int> dfs1(vector<vector<int>> &g, vector<int> &d_o, vector<int> &de, int u, int p) {
    pair<int, int> res = {0, 1};
    for (int x: g[u]) {
        if (x != p) {
            auto t = dfs1(g, d_o, de, x, u);
            res.first += t.second;
            res.second += t.first;
        }
    }
    d_o[u] = res.first;
    de[u] = res.second;
    return res;
}

void dfs2(vector<vector<int>> &g, vector<int> &d_o, vector<int> &de, vector<int> &uo, vector<int> &ue, int u, int p) {
    if (p != -1) {
        uo[u] = de[p] - d_o[u] + ue[p];
        ue[u] = d_o[p] - de[u] + uo[p];
    }
    for (int x: g[u]) {
        if (x != p) {
            dfs2(g, d_o, de, uo, ue, x, u);
        }
    }
};

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2) {
        int n = static_cast<int>(edges1.size()) + 1, m = static_cast<int>(edges2.size()) + 1;
        vector<vector<int>> g1(n), g2(m);
        for (auto &e: edges1) {
            g1[e[0]].emplace_back(e[1]);
            g1[e[1]].emplace_back(e[0]);
        }
        for (auto &e: edges2) {
            g2[e[0]].emplace_back(e[1]);
            g2[e[1]].emplace_back(e[0]);
        }
        vector<int> do1(n), de1(n);
        vector<int> do2(m), de2(m);
        dfs1(g1, do1, de1, 0, -1);
        dfs1(g2, do2, de2, 0, -1);

        vector<int> uo1(n), ue1(n);
        vector<int> uo2(m), ue2(m);
        dfs2(g1, do1, de1, uo1, ue1, 0, -1);
        dfs2(g2, do2, de2, uo2, ue2, 0, -1);
        int mo2 = 0, me2 = 0;
        for (int j = 0; j < m; j++) {
            mo2 = max(mo2, do2[j] + uo2[j]);
            me2 = max(me2, de2[j] + ue2[j]);
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int e = de1[i] + ue1[i];
            res[i] = e + mo2;
        }
        return res;
    }
};