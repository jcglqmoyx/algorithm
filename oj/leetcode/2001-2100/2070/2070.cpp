#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
        auto n = items.size(), m = queries.size();
        sort(items.begin(), items.end());
        int id[m];
        iota(id, id + m, 0);
        sort(id, id + m, [&](int i, int j) {
            return queries[i] < queries[j];
        });
        vector<int> res(m);
        for (int mx = 0, i = 0, j = 0; j < m; j++) {
            while (i < n && items[i][0] <= queries[id[j]]) {
                mx = max(mx, items[i][1]);
                i++;
            }
            res[id[j]] = mx;
        }
        return res;
    }
};