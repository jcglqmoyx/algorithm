#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfPower(vector<int> &nums, int k) {
        const int MOD = 1e9 + 7;
        long long f[k + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int x: nums) {
            for (int i = k; i >= 0; i--) {
                f[i] = f[i] * 2 % MOD;
                if (i >= x) {
                    f[i] = (f[i] + f[i - x]) % MOD;
                }
            }
        }
        return f[k];
    }
};