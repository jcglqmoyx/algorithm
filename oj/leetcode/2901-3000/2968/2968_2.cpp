#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFrequencyScore(vector<int> &nums, long long k) {
        sort(nums.begin(), nums.end());
        long long s = 0;
        int res = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            s += nums[r] - nums[(l + r) / 2];
            while (s > k) {
                s -= nums[(l + r + 1) / 2] - nums[l];
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};