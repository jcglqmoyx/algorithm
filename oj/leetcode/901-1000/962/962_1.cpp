#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        int id[n];
        iota(id, id + n, 0);
        sort(id, id + n, [&](int i, int j) {
            if (nums[i] == nums[j]) return i < j;
            return nums[i] < nums[j];
        });
        int res = 0;
        for (int i = 0, m = n; i < n; i++) {
            res = max(res, id[i] - m);
            m = min(m, id[i]);
        }
        return res;
    }
};