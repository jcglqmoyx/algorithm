#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumANDSum(vector<int> &nums, int numSlots) {
        vector<int> f(1 << (numSlots * 2));
        for (int i = 0; i < f.size(); ++i) {
            int c = __builtin_popcount(i);
            if (c >= nums.size()) continue;
            for (int j = 0; j < numSlots * 2; ++j) {
                if ((i & (1 << j)) == 0) {
                    int s = i | (1 << j);
                    f[s] = max(f[s], f[i] + ((j / 2 + 1) & nums[c]));
                }
            }
        }
        return *max_element(f.begin(), f.end());
    }
};