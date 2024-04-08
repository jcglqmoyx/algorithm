#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums) {
        int n = nums.size(), res = n - 1;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int m = nums.size();
        for (int i = 0; i < m; i++) {
            int j = upper_bound(nums.begin() + i, nums.end(), nums[i] + n - 1) - nums.begin();
            res = min(res, n - (j - i));
        }
        return res;
    }
};