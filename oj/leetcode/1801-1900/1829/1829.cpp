#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
        auto n = nums.size();
        int s = 0;
        for (int x: nums) {
            s ^= x;
        }
        vector<int> res(n);
        int mx = (1 << maximumBit) - 1;
        for (int i = 0; i < n; i++) {
            res[i] = s ^ mx;
            s ^= nums[n - i - 1];
        }
        return res;
    }
};