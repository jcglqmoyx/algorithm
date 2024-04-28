#include <bits/stdc++.h>

using namespace std;

const int N = 30010;

int h[N], e[N << 1], ne[N << 1], idx;

int sz[N];
int down[N], up[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

pair<int, int> dfs1(int u, int p) {
    sz[u] = 1, down[u] = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j != p) {
            auto t = dfs1(j, u);
            sz[u] += t.first;
            down[u] += t.second + t.first;
        }
    }
    return {sz[u], down[u]};
}

void dfs2(int u, int p, int n) {
    up[u] = 0;
    if (p != -1) {
//        up[u] = (up[p] + n - sz[p] + 1) + (down[p] - down[u] - 1 - sz[u] + sz[p] - sz[u]);
        up[u] = up[p] + n + down[p] - down[u] - sz[u] * 2;
    }
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j != p) {
            dfs2(j, u, n);
        }
    }
}

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        memset(h, -1, sizeof(int) * n), idx = 0;
        for (auto &edge: edges) {
            add(edge[0], edge[1]);
            add(edge[1], edge[0]);
        }
        dfs1(0, -1);
        dfs2(0, -1, n);
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = up[i] + down[i];
        }
        return res;
    }
};