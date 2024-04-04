#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfPowers(vector<int> &nums, int k) {
        int n = nums.size(), MOD = 1e9 + 7, res = 0;
        sort(nums.begin(), nums.end());
        int f[n + 1][k + 1], g[n + 1][k + 1];

        auto helper = [&](int a, int b, int diff) {
            memset(f, 0, sizeof f);
            memset(g, 0, sizeof g);
            int res = 0;
            for (int i = 1; i <= a; i++) f[i][1] = 1;
            for (int i = b; i <= n; i++) g[i][1] = 1;
            for (int i = 1; i <= a; i++) {
                for (int j = 2; j <= k; j++) {
                    for (int u = 1; nums[i - 1] - nums[u - 1] >= diff && u < i; u++) {
                        f[i][j] = (f[i][j] + f[u][j - 1]) % MOD;
                    }
                }
            }
            for (int i = n; i >= b; i--) {
                for (int j = 2; j <= k; j++) {
                    for (int u = n; nums[u - 1] - nums[i - 1] > diff && u > i; u--) {
                        g[i][j] = (g[i][j] + g[u][j - 1]) % MOD;
                    }
                }
            }
            for (int l = 1; l < k; l++) {
                res = (res + f[a][l] * 1LL * g[b][k - l] % MOD) % MOD;
            }
            return res * 1LL * diff % MOD;
        };
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (n - (j - i + 1) < k - 2) continue;
                res = (res + helper(i, j, nums[j - 1] - nums[i - 1])) % MOD;
            }
        }
        return res;
    }
};