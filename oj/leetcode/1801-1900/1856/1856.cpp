#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSumMinProduct(vector<int> &nums) {
        int n = nums.size(), m = 1e9 + 7;
        long long s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        int l[n], stk[n], tt = -1;
        for (int i = 0; i < n; i++) {
            while (tt >= 0 && nums[stk[tt]] >= nums[i]) tt--;
            l[i] = tt == -1 ? 0 : stk[tt] + 1;
            stk[++tt] = i;
        }
        long long res = 0;
        tt = -1;
        for (int i = n - 1; i >= 0; i--) {
            while (tt >= 0 && nums[stk[tt]] > nums[i]) tt--;
            int ri = tt == -1 ? n - 1 : stk[tt] - 1;
            res = max(res, nums[i] * (s[ri + 1] - s[l[i]]));
            stk[++tt] = i;
        }
        return res % m;
    }
};