#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > s) {
            return 0;
        }
        unordered_map<int, int> f;
        f[0] = 1;
        for (int x: nums) {
            unordered_map<int, int> g;
            for (int i = -s; i <= s; i++) {
                g[i] = (f[i - x] + f[i + x]);
            }
            f = std::move(g);
        }
        return f[target];
    }
};