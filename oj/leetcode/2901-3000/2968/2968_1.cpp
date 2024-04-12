#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFrequencyScore(vector<int> &nums, long long k) {
        using LL = long long;
        sort(nums.begin(), nums.end());
        auto n = nums.size();
        LL s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        auto check = [&](int len) {
            for (int i = len; i <= n; i++) {
                LL l = i - len + 1, r = i;
                LL u = (l + r) >> 1;
                if (nums[u - 1] * (u - l + 1) - (s[u] - s[l - 1]) + s[i] - s[u] - nums[u - 1] * 1LL * (len / 2) <= k) {
                    return true;
                }
            }
            return false;
        };
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};