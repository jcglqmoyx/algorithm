#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countQuadruplets(vector<int> &nums) {
        using ll = long long;
        auto n = nums.size();
        ll res = 0;
        int pre[n + 1];
        memset(pre, 0, sizeof pre);
        for (int j = 0; j + 2 < n; j++) {
            int suf = 0;
            for (int k = n - 1; k > j; k--) {
                if (nums[k] > nums[j]) suf++;
                else res += pre[nums[k]] * suf;
            }
            for (int x = nums[j] + 1; x <= n; x++) {
                pre[x]++;
            }
        }
        return res;
    }
};