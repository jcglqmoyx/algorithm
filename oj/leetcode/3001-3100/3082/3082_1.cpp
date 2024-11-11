#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfPower(vector<int> &nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        int p[n + 1];
        p[0] = 1;
        for (int i = 1; i <= n; i++) p[i] = p[i - 1] * 2 % MOD;
        int f[n + 1][k + 1];
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int x: nums) {
            for (int i = n; i >= 1; i--) {
                for (int j = k; j >= x; j--) {
                    f[i][j] = (f[i][j] + f[i - 1][j - x]) % MOD;
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res = (int) ((res + f[i][k] * 1LL * p[n - i]) % MOD);
        }
        return res;
    }
};