#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minArraySum(vector<int> &nums, int k, int op1, int op2) {
        int n = static_cast<int>(nums.size());
        int f[op1 + 1][op2 + 1];
        memset(f, 0, sizeof f);
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];
            for (int j = op1; j >= 0; j--) {
                for (int u = op2; u >= 0; u--) {
                    if (j) f[j][u] = max(f[j][u], f[j - 1][u] + x / 2);
                    if (u && x >= k) {
                        f[j][u] = max(f[j][u], f[j][u - 1] + k);
                        if (j) {
                            f[j][u] = max(f[j][u], f[j - 1][u - 1] + k + (x - k) / 2);
                            if ((x + 1) / 2 >= k) {
                                f[j][u] = max(f[j][u], f[j - 1][u - 1] + x / 2 + k);
                            }
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= op1; i++) {
            for (int j = 0; j <= op2; j++) {
                res = max(res, f[i][j]);
            }
        }
        return accumulate(nums.begin(), nums.end(), 0) - res;
    }
};