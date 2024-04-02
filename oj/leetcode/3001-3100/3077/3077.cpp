#include <bits/stdc++.h>

using namespace std;

/*
class Solution {
public:
    long long maximumStrength(vector<int> &nums, int k) {
        size_t n = nums.size();
        long long f[n + 1][k + 1][2];
        memset(f, -0x3f, sizeof f);
        f[0][0][0] = 0;
        for (int i = 1; i <= n; i++) {
            f[i][0][0] = 0;
            for (int j = 1; j <= min(i, k); j++) {
                long long x = nums[i - 1];
                f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1]);

                long long t = x * (k - j + 1) * (j & 1 ? 1 : -1);
                f[i][j][1] = max(max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]) + t, f[i - 1][j][1] + t);
            }
        }
        return max(f[n][k][0], f[n][k][1]);
    }
};
 */

class Solution {
public:
    long long maximumStrength(vector<int> &nums, int k) {
        long long f[k + 1][2];
        memset(f, -0x3f, sizeof f);
        f[0][0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = min(i, k); j >= 1; j--) {
                long long x = nums[i - 1];
                f[j][0] = max(f[j][0], f[j][1]);

                long long t = x * (k - j + 1) * (j & 1 ? 1 : -1);
                f[j][1] = max(max(f[j - 1][0], f[j - 1][1]) + t, f[j][1] + t);
            }
        }
        return max(f[k][0], f[k][1]);
    }
};