#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>> &queries) {
        int p[n + 1];
        iota(p, p + n + 1, 0);

        function<int(int)> find = [&](int x) {
            if (p[x] != x) p[x] = find(p[x]);
            return p[x];
        };
        auto connect = [&](int x, int y) {
            int px = find(x), py = find(y);
            if (px != py) {
                p[py] = px;
            }
        };
        for (int x = threshold + 1; x <= n / 2; x++) {
            for (int y = x << 1; y <= n; y += x) {
                connect(x, y);
            }
        }
        auto m = queries.size();
        vector<bool> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = find(queries[i][0]) == find(queries[i][1]);
        }
        return res;
    }
};