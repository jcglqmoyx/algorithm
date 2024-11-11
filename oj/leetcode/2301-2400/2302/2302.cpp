#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int> &nums, long long k) {
        long long s = 0, res = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            s += nums[r];
            while (s * (r - l + 1) >= k) {
                s -= nums[l];
                l++;
            }
            res += r - l + 1;
        }
        return res;
    }
};