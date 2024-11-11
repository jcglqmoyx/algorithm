#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int h[N], e[N << 1], ne[N << 1], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int diameter(vector<vector<int>> &edges) {
    idx = 0;
    if (edges.empty()) {
        return 0;
    }
    auto n = edges.size() + 1;
    memset(h, -1, sizeof(int) * n);
    for (auto &edge: edges) {
        add(edge[0], edge[1]);
        add(edge[1], edge[0]);
    }
    int node = 0, diameter = 0;
    function<void(int, int, int)> dfs = [&](int u, int p, int d) {
        if (d > diameter) {
            diameter = d;
            node = u;
        }
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (j != p) {
                dfs(j, u, d + 1);
            }
        }
    };
    dfs(0, -1, 0);
    dfs(node, -1, 0);
    return diameter;
}

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2) {
        int d1 = diameter(edges1);
        int d2 = diameter(edges2);
        return max({(d1 + 1) / 2 + (d2 + 1) / 2 + 1, d1, d2});
    }
};