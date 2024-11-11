#include  <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int m = *max_element(nums.begin(), nums.end());
        int diff[m + 2];
        memset(diff, 0, sizeof diff);
        for (int x: nums) {
            diff[max(0, x - k)]++;
            diff[min(m + 1, x + k + 1)]--;
        }
        int res = 0, s = 0;
        for (int x: diff) {
            s += x;
            res = max(res, s);
        }
        return res;
    }
};