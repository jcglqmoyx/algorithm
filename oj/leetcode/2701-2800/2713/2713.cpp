#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>> &mat) {
        auto n = mat.size(), m = mat[0].size();
        int r[n], c[m];
        memset(r, 0, sizeof r);
        memset(c, 0, sizeof c);
        map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mp[mat[i][j]].emplace_back(i, j);
            }
        }
        for (auto &[_, p]: mp) {
            int res[p.size()];
            memset(res, 0, sizeof res);
            for (int i = 0; i < p.size(); i++) {
                res[i] = max(r[p[i].first], c[p[i].second]) + 1;
            }
            for (int i = 0; i < p.size(); i++) {
                r[p[i].first] = max(r[p[i].first], res[i]);
                c[p[i].second] = max(c[p[i].second], res[i]);
            }
        }
        return *max_element(r, r + n);
    }
};