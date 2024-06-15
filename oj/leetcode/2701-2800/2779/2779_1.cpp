#include  <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            while (nums[r] - k * 2 > nums[l]) l++;
            res = max(res, r - l + 1);
        }
        return res;
    }
};