#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums) {
        size_t n = nums.size();
        int l = 0, r = 0;
        for (int x: nums) r += x;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            l += nums[i];
            r -= nums[i];
            res[i] = nums[i] * ((i + 1) * 2 - n) + r - l;
        }
        return res;
    }
};