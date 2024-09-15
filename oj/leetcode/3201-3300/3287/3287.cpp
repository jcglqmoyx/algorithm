#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxValue(vector<int> &nums, int k) {
        int n = nums.size();
        int mx = 1 << 7;
        bool l[n - k + 1][mx];
        memset(l, 0, sizeof l);
        int f[k + 1][mx];
        memset(f, 0, sizeof f);
        f[0][0] = true;
        for (int i = 1; i + k - 1 < n; i++) {
            for (int j = min(k - 1, i); j >= 0; j--) {
                for (int num = 0; num < mx; num++) {
                    if (f[j][num]) f[j + 1][num | nums[i - 1]] = true;
                }
            }
            for (int num = 1; num < mx; num++) {
                l[i][num] = f[k][num];
            }
        }
        memset(f, 0, sizeof f);
        f[0][0] = true;
        int res = 0;
        for (int i = n; i > k; i--) {
            for (int j = min(k - 1, n - i + 1); j >= 0; j--) {
                for (int num = 0; num < mx; num++) {
                    if (f[j][num]) f[j + 1][num | nums[i - 1]] = true;
                }
            }
            for (int right = 1; right < mx; right++) {
                if (f[k][right]) {
                    for (int left = 1; left < mx; left++) {
                        if (l[i - 1][left]) {
                            res = max(res, left ^ right);
                        }
                    }
                }
            }
        }
        return res;
    }
};