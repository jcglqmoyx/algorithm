#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int> &nums, int k) {
        long long res = 0;
        for (int l = 0, r = 0, i = 0; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0 && (nums[j] & nums[i]) != nums[j]; j--) {
                nums[j] &= nums[i];
            }
            while (l <= i && nums[l] < k) l++;
            while (r <= i && nums[r] <= k) r++;
            res += r - l;
        }
        return res;
    }
};