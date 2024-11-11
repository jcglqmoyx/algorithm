#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> cnt;
        long long s = 0, res = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            cnt[nums[r]]++;
            s += nums[r];
            if (r >= k - 1) {
                if (cnt.size() == k) res = max(res, s);
                if (--cnt[nums[l]] == 0) {
                    cnt.erase(nums[l]);
                }
                s -= nums[l];
                l++;
            }
        }
        return res;
    }
};