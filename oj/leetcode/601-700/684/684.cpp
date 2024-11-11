#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        auto n = edges.size();
        int p[n + 1];
        iota(p, p + n + 1, 0);
        auto find = [&](auto &&find, int x) -> int {
            if (p[x] != x) p[x] = find(find, p[x]);
            return p[x];
        };
        for (auto &e: edges) {
            int a = e[0], b = e[1];
            int pa = find(find, a), pb = find(find, b);
            if (pa != pb) {
                p[pa] = pb;
            } else {
                return e;
            }
        }
        return {};
    }
};