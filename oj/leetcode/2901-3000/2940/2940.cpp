#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries) {
        struct Node {
            int val, idx;
            int type;

            bool operator<(const Node &node) const {
                if (val == node.val) return idx > node.idx;
                return val > node.val;
            }
        };
        int n = (int) heights.size(), m = (int) queries.size();
        vector<Node> v(n);
        vector<int> res(m);
        for (int i = 0; i < n; i++) v[i] = {heights[i], n - i, i};
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0], b = queries[i][1];
            if (a > b) swap(a, b);
            if (a == b || heights[a] < heights[b]) res[i] = b;
            else v.push_back({heights[a], n - b, -i - 1});
        }
        sort(v.begin(), v.end());

        int sz = (int) v.size();
        int tr[sz + 1], INF = 0x3f3f3f3f;
        memset(tr, 0x3f, sizeof tr);
        auto lb = [](int x) { return x & -x; };
        auto update = [&](int x, int val) {
            for (; x <= sz; x += lb(x)) tr[x] = min(tr[x], val);
        };
        auto query = [&](int x) {
            int res = INF;
            for (; x; x -= lb(x)) res = min(res, tr[x]);
            return res == INF ? -1 : res;
        };
        for (auto &e: v) {
            if (e.type < 0) {
                res[-(e.type + 1)] = query(e.idx - 1);
            } else {
                update(e.idx, e.type);
            }
        }
        return res;
    }
};