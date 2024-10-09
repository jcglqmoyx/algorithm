#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int> &nums, int k) {
        int res = INT32_MAX;
        for (int i = 0; i < nums.size(); i++) {
            res = min(res, abs(nums[i] - k));
            for (int j = i - 1; j >= 0 && (nums[j] | nums[i]) != nums[j]; j--) {
                nums[j] |= nums[i];
                res = min(res, abs(nums[j] - k));
            }
        }
        return res;
    }
};