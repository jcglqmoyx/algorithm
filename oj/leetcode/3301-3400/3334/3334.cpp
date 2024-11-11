#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxScore(vector<int> &nums) {
        using LL = long long;
        int n = static_cast<int>(nums.size());
        LL pre_gcd[n], pre_lcm[n];
        LL suf_gcd[n], suf_lcm[n];
        pre_gcd[0] = pre_lcm[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre_gcd[i] = gcd(pre_gcd[i - 1], nums[i]);
            pre_lcm[i] = lcm(pre_lcm[i - 1], nums[i]);
        }
        suf_gcd[n - 1] = suf_lcm[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf_gcd[i] = gcd(suf_gcd[i + 1], nums[i]);
            suf_lcm[i] = lcm(suf_lcm[i + 1], nums[i]);
        }
        LL res = pre_gcd[n - 1] * pre_lcm[n - 1];
        if (n > 1) {
            res = max(res, pre_gcd[n - 2] * pre_lcm[n - 2]);
            res = max(res, suf_gcd[1] * suf_lcm[1]);
        }
        for (int i = 1; i < n - 1; i++) {
            res = max(res, gcd(pre_gcd[i - 1], suf_gcd[i + 1]) * lcm(pre_lcm[i - 1], suf_lcm[i + 1]));
        }
        return res;
    }
};
