#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canSortArray(vector<int> &nums) {
        auto n = nums.size();
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int bits = __builtin_popcount(nums[i]);
            while (j < n && __builtin_popcount(nums[j]) == bits) {
                j++;
            }
            sort(nums.begin() + i, nums.begin() + j);
            i = j - 1;
        }
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    }
};