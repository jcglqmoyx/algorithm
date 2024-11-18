#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
        int n = static_cast<int>(nums.size()), d[n + 2], m = static_cast<int>(queries.size());
        memset(d, 0, sizeof d);
        int j = 0;
        for (int s = 0, i = 0; i < n; i++) {
            s += d[i];
            for (; nums[i] > s && j < m; j++) {
                int l = queries[j][0], r = queries[j][1], val = queries[j][2];
                if (r < i) {
                    continue;
                }
                d[r + 1] -= val;
                if (l <= i && i <= r) {
                    s += val;
                } else {
                    d[l] += val;
                }
            }
            if (j == m && nums[i] > s) {
                return -1;
            }
        }
        return j;
    }
};