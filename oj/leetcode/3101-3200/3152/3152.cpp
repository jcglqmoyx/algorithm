#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
        int n = nums.size(), m = queries.size();
        int r[n];
        r[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            r[i] = (nums[i + 1] & 1) == (nums[i] & 1) ? i : r[i + 1];
        }
        vector<bool> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = queries[i][1] <= r[queries[i][0]];
        }
        return res;
    }
};