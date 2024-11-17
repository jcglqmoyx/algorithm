#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
        int n = static_cast<int>(queries.size()), m = static_cast<int>(nums.size()), d[m + 2];
        int l = 0, r = n + 1;
        auto check = [&](int mid) {
            memset(d, 0, sizeof d);
            for (int i = 0; i < mid; i++) {
                d[queries[i][0]] -= queries[i][2];
                d[queries[i][1] + 1] += queries[i][2];
            }
            for (int s = 0, i = 0; i < m; i++) {
                s += d[i];
                if (nums[i] + s > 0) {
                    return false;
                }
            }
            return true;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l == n + 1 ? -1 : l;
    }
};