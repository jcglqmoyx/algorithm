#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries) {
        sort(edgeList.begin(), edgeList.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });
        auto m = queries.size();
        struct Q {
            int from, to, limit, idx;
        } query[m];
        for (int i = 0; i < m; i++) {
            query[i] = {queries[i][0], queries[i][1], queries[i][2], i};
        }
        sort(query, query + m, [](auto &a, auto &b) {
            return a.limit < b.limit;
        });

        int p[n], sz[n];
        iota(p, p + n, 0);
        fill(sz, sz + n, 1);
        auto find = [&](auto &&find, int x) -> int {
            if (p[x] != x) p[x] = find(find, p[x]);
            return p[x];
        };
        auto connect = [&](int a, int b) {
            int pa = find(find, a), pb = find(find, b);
            if (pa == pb) return;
            if (sz[pa] > sz[pb]) swap(pa, pb);
            p[pa] = pb;
            sz[pb] += sz[pa];
        };
        vector<bool> res(m);
        int u = 0;
        for (int i = 0; i < m; i++) {
            auto &q = query[i];
            while (u < edgeList.size() && edgeList[u][2] < q.limit) {
                connect(edgeList[u][0], edgeList[u][1]);
                u++;
            }
            res[q.idx] = find(find, q.from) == find(find, q.to);
        }
        return res;
    }
};