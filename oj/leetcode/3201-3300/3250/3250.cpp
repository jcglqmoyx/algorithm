#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countOfPairs(vector<int> &nums) {
        const int M = 1e9 + 7;
        auto n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        int f[m + 1], g[m + 1];
        memset(f, 0, sizeof f);
        for (int j = 0; j <= nums[0]; j++) {
            f[j] += (j ? f[j - 1] : 0) + 1;
        }
        memcpy(g, f, sizeof f);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= nums[i]; j++) {
                int limit = min(0, nums[i - 1] - nums[i]) + j;
                if (limit < 0) {
                    f[j] = 0;
                } else {
                    f[j] = ((j ? f[j - 1] : 0) + g[limit]) % M;
                }
            }
            memcpy(g, f, sizeof f);
        }
        return f[nums.back()];
    }
};