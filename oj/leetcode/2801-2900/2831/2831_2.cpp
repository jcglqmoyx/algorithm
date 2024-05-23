#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestEqualSubarray(vector<int> &nums, int k) {
        int res = 0;
        unordered_map<int, int> cnt;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            cnt[nums[r]]++;
            if (r - l + 1 - cnt[nums[l]] > k) {
                cnt[nums[l]]--;
                l++;
            }
            res = max(res, cnt[nums[r]]);
        }
        return res;
    }
};