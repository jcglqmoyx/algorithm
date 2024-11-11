#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int> &nums, int k) {
        int ans = INT_MAX, left = 0, bottom = 0, right_or = 0;
        for (int right = 0; right < nums.size(); right++) {
            right_or |= nums[right];
            while (left <= right && (nums[left] | right_or) > k) {
                ans = min(ans, (nums[left] | right_or) - k);
                if (bottom <= left) {
                    for (int i = right - 1; i > left; i--) {
                        nums[i] |= nums[i + 1];
                    }
                    bottom = right;
                    right_or = 0;
                }
                left++;
            }
            if (left <= right) {
                ans = min(ans, k - (nums[left] | right_or));
            }
        }
        return ans;
    }
};
