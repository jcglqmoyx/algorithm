#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        int l[n], v[n];
        for (int idx = 0, i = 0; i < n; i++) {
            if (idx == 0 || nums[i] > v[idx - 1]) {
                v[idx++] = nums[i];
                l[i] = idx;
            } else {
                int p = static_cast<int>((lower_bound(v, v + idx, nums[i]) - v));
                v[p] = nums[i];
                l[i] = p + 1;
            }
        }
        int res = n;
        for (int idx = 0, i = n - 1; i >= 0; i--) {
            int ri;
            if (idx == 0 || nums[i] > v[idx - 1]) {
                v[idx++] = nums[i];
                ri = idx;
            } else {
                int p = static_cast<int>((lower_bound(v, v + idx, nums[i]) - v));
                v[p] = nums[i];
                ri = p + 1;
            }
            if (l[i] > 1 && ri > 1) {
                res = min(res, n - l[i] - ri + 1);
            }
        }
        return res;
    }
};