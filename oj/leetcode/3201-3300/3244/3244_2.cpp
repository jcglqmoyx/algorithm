#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
        int ne[n];
        iota(ne, ne + n, 1);
        auto m = queries.size();
        vector<int> res(m);
        for (int dist = n - 1, i = 0; i < m; i++) {
            int u = queries[i][0], v = queries[i][1];
            if (ne[u] && ne[u] < v) {
                int j = u + 1;
                while (j && j < v) {
                    int nj = ne[j];
                    ne[j] = 0;
                    j = nj;
                    dist--;
                }
                ne[u] = v;
            }
            res[i] = dist;
        }
        return res;
    }
};