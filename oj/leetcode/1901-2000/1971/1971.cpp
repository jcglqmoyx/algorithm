#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        int p[n], sz[n];
        iota(p, p + n, 0);
        fill(sz, sz + n, 1);
        function<int(int)> find = [&](int x) {
            if (p[x] != x) p[x] = find(p[x]);
            return p[x];
        };
        for (auto &e: edges) {
            int px = find(e[0]), py = find(e[1]);
            if (px == py) continue;
            if (sz[px] > sz[py]) swap(px, py);
            sz[py] += sz[px];
            p[px] = py;
        }
        return find(source) == find(destination);
    }
};