#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int> &nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int cnt[mx + 1];
        memset(cnt, 0, sizeof cnt);
        for (int x: nums) cnt[x]++;
        for (int i = 0, x = 0; x <= mx; x++) {
            while (cnt[x]--) {
                nums[i++] = x;
            }
        }
        int res = nums.back() - nums.front();
        for (int i = 0; i + 1 < nums.size(); i++) {
            res = min(res, max(nums[i] + k, nums.back() - k) - min(nums[0] + k, nums[i + 1] - k));
        }
        return res;
    }
};