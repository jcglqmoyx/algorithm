#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>&nums, int k) {
        if (k <= 1) return 0;
        int res = 0;
        for (int l = 0, r = 0, p = 1; r < nums.size(); r++) {
            p *= nums[r];
            while (p >= k) p /= nums[l], l++;
            res += r - l + 1;
        }
        return res;
    }
};
