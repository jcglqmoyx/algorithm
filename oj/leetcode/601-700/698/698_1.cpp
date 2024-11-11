#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if (tot % k) {
            return false;
        }

        int sub = tot / k;
        if (*max_element(nums.begin(), nums.end()) > sub) {
            return false;
        }

        auto n = nums.size();
        int s[1 << n];
        memset(s, 0, sizeof s);
        bool f[1 << n];
        memset(f, 0, sizeof f);
        f[0] = true;
        for (int i = 0; i < 1 << n; i++) {
            if (!f[i]) continue;
            for (int j = 0; j < n; j++) {
                if (!(i >> j & 1) && s[i] + nums[j] <= sub) {
                    int u = i | (1 << j);
                    s[u] = s[i] + nums[j];
                    if (s[u] == sub) s[u] = 0;
                    f[u] = true;
                }
            }
        }
        return f[(1 << n) - 1];
    }
};