#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
        auto n = nums.size(), m = queries.size();
        int tr[n * 31][2], idx = 0;
        int mn[n * 31];
        memset(tr, 0, sizeof tr);
        memset(mn, 0x3f, sizeof mn);
        auto insert = [&](int x) {
            int p = 0;
            for (int i = 30; ~i; i--) {
                int u = x >> i & 1;
                if (!tr[p][u]) tr[p][u] = ++idx;
                p = tr[p][u];
                mn[p] = min(mn[p], x);
            }
        };
        int min_value = 1e9;
        for (int x: nums) {
            min_value = min(min_value, x);
            insert(x);
        }
        vector<int> res(m);
        for (int it = 0; it < m; it++) {
            int xi = queries[it][0], mi = queries[it][1];
            if (mi < min_value) {
                res[it] = -1;
            } else {
                int num = 0;
                for (int p = 0, i = 30; ~i; i--) {
                    int u = xi >> i & 1;
                    if (tr[p][!u] && mn[tr[p][!u]] <= mi) {
                        p = tr[p][!u];
                        num += (1 << i) * (!u);
                    } else {
                        p = tr[p][u];
                        num += (1 << i) * u;
                    }
                }
                res[it] = num ^ xi;
            }
        }
        return res;
    }
};