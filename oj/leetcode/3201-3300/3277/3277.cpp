#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int> &nums, vector<vector<int>> &queries) {
        auto n = nums.size();
        int f[n][n], mx[n][n];
        memset(f, 0, sizeof f);
        memset(mx, 0, sizeof mx);
        for (int i = n - 1; ~i; i--) {
            mx[i][i] = f[i][i] = nums[i];
            for (int j = i + 1; j < n; j++) {
                f[i][j] = f[i][j - 1] ^ f[i + 1][j];
                mx[i][j] = max({f[i][j], mx[i][j - 1], mx[i + 1][j]});
            }
        }
        vector<int> res;
        res.reserve(queries.size());
        for (auto &q: queries) {
            res.emplace_back(mx[q[0]][q[1]]);
        }
        return res;
    }
};