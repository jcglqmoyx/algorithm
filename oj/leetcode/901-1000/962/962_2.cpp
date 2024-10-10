#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int> &nums) {
        int n = static_cast<int>(nums.size()), res = 0;
        int stk[n], idx = 0;
        stk[idx++] = 0;
        for (int i = 1; i < n; i++) {
            if (nums[stk[idx - 1]] > nums[i]) {
                stk[idx++] = i;
            }
        }
        for (int i = n - 1; i; i--) {
            while (idx && nums[stk[idx - 1]] <= nums[i]) {
                res = max(res, i - stk[idx - 1]);
                idx--;
            }
        }
        return res;
    }
};