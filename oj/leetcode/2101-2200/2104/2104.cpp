#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int> &nums) {
        auto n = nums.size();
        int l_min[n], l_max[n], stk[n];
        for (int tt = -1, i = 0; i < n; i++) {
            while (~tt && nums[stk[tt]] >= nums[i]) tt--;
            l_min[i] = ~tt ? stk[tt] + 1 : 0;
            stk[++tt] = i;
        }
        for (int tt = -1, i = 0; i < n; i++) {
            while (~tt && nums[stk[tt]] <= nums[i]) tt--;
            l_max[i] = ~tt ? stk[tt] + 1 : 0;
            stk[++tt] = i;
        }
        long long res = 0;
        for (int tt = -1, i = n - 1; i >= 0; i--) {
            while (~tt && nums[stk[tt]] > nums[i]) tt--;
            int r_min = ~tt ? stk[tt] - 1 : n - 1;
            res -= (long long) nums[i] * (i - l_min[i] + 1) * (r_min - i + 1);
            stk[++tt] = i;
        }
        for (int tt = -1, i = n - 1; i >= 0; i--) {
            while (~tt && nums[stk[tt]] < nums[i]) tt--;
            int r_max = ~tt ? stk[tt] - 1 : n - 1;
            res += (long long) nums[i] * (i - l_max[i] + 1) * (r_max - i + 1);
            stk[++tt] = i;
        }
        return res;
    }
};