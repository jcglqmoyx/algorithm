#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        auto n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        auto f = [&](int start) {
            int a = nums[start], b = max(nums[start], nums[start + 1]);
            for (int i = start + 2; i < n + start - 1; i++) {
                int c = max(a + nums[i], b);
                a = b, b = c;
            }
            return max(a, b);
        };
        return max(f(0), f(1));
    }
};