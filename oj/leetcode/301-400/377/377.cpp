#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        int f[target + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int x: nums) {
                if (i >= x && INT32_MAX - f[i] >= f[i - x]) {
                    f[i] += f[i - x];
                }
            }
        }
        return f[target];
    }
};
