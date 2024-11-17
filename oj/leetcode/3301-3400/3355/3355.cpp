#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
        int n = static_cast<int>(nums.size()), diff[n + 2];
        memset(diff, 0, sizeof diff);
        for (auto &q: queries) {
            diff[q[0]]--, diff[q[1] + 1]++;
        }
        for (int s = 0, i = 0; i < n; i++) {
            s += diff[i];
            if (nums[i] + s > 0) {
                return false;
            }
        }
        return true;
    }
};