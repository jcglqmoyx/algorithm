#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDifference(vector<int> &nums) {
        int n = nums.size();
        if (n <= 4) return 0;
        sort(nums.begin(), nums.end());
        int res = 2e9;
        if (n == 5) {
            for (int i = 1; i < n; i++) {
                res = min(res, nums[i] - nums[i - 1]);
            }
        } else {
            res = min(res, nums[n - 1] - nums[3]);
            res = min(res, nums[n - 2] - nums[2]);
            res = min(res, nums[n - 3] - nums[1]);
            res = min(res, nums[n - 4] - nums[0]);
        }
        return res;
    }
};