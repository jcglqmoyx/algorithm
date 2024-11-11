#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSum(vector<int> &nums) {
        int n = nums.size(), l[n], res = 1e9;
        memset(l, 0x3f, sizeof l);
        for (int mn = 1e9, i = 0; i < n; i++) {
            l[i] = mn;
            mn = min(mn, nums[i]);
        }
        for (int r = 1e9, i = n - 1; i >= 0; i--) {
            if (l[i] < nums[i] && r < nums[i]) res = min(res, l[i] + nums[i] + r);
            r = min(r, nums[i]);
        }
        return res == 1e9 ? -1 : res;
    }
};
