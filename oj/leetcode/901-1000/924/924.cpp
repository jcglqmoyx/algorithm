#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n;
    vector<int> p, w;

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    void add(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py) {
            if (w[px] > w[py]) swap(px, py);
            w[py] += w[px];
            p[px] = py;
        }
    }

    int weight(int x) {
        return w[find(x)];
    }

public:
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial) {
        this->n = graph.size();
        p.resize(n), w.resize(n, 1);
        iota(p.begin(), p.end(), 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j]) {
                    add(i, j);
                }
            }
        }
        int res = -1, m = 0;
        vector<bool> st(n);
        for (auto x: initial) st[x] = true;
        for (int idx = 0, i = 0; i < n; i++) {
            if (st[i]) initial[idx++] = i;
        }
        queue<int> q;
        for (int x: initial) q.emplace(x);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            int pt = find(t);
            bool ok = true;
            for (auto it = q.size(); it; it--) {
                int x = q.front();
                q.pop();
                int px = find(x);
                if (px == pt) {
                    ok = false;
                } else {
                    q.emplace(x);
                }
            }
            if (ok) {
                if (w[pt] > m) {
                    m = w[pt];
                    res = t;
                }
            } else if (res == -1) {
                res = t;
            }
        }
        return res;
    }
};