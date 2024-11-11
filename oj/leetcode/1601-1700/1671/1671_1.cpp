#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        int l[n], r[n];
        for (int i = 0; i < n; i++) {
            l[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    l[i] = max(l[i], l[j] + 1);
                }
            }
        }
        int res = n;
        for (int i = n - 1; ~i; i--) {
            r[i] = 1;
            for (int j = n - 1; j > i; j--) {
                if (nums[j] < nums[i]) {
                    r[i] = max(r[i], r[j] + 1);
                }
            }
            if (l[i] > 1 && r[i] > 1) {
                res = min(res, n - l[i] - r[i] + 1);
            }
        }
        return res;
    }
};