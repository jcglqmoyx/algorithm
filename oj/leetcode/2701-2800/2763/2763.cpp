#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumImbalanceNumbers(vector<int> &nums) {
        auto n = nums.size();
        int p[n + 2], l[n];
        memset(p, -1, sizeof p);
        for (int i = 0; i < n; i++) {
            l[i] = p[nums[i] + 1] + 1;
            p[nums[i]] = i;
        }
        fill(p, p + n + 2, n);
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            int ri = min(p[nums[i] + 1], p[nums[i]]) - 1;
            res += (i - l[i] + 1) * (ri - i + 1);
            p[nums[i]] = i;
        }
        return res - n * (n + 1) / 2;
    }
};