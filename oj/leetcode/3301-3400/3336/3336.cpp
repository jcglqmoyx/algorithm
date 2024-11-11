#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subsequencePairCount(vector<int> &nums) {
        int n = static_cast<int>(nums.size()), m = *max_element(nums.begin(), nums.end()), MOD = 1e9 + 7;
        int f[n][m + 1][m + 1];
        memset(f, -1, sizeof f);
        auto dp = [&](auto &&dp, int u, int x, int y) -> int {
            if (u == n) {
                return x == y;
            }
            if (f[u][x][y] != -1) return f[u][x][y];
            int &res = f[u][x][y];
            res = (dp(dp, u + 1, gcd(x, nums[u]), y) + dp(dp, u + 1, x, gcd(y, nums[u]))) % MOD;
            res = (res + dp(dp, u + 1, x, y)) % MOD;
            return res;
        };
        return (dp(dp, 0, 0, 0) - 1 + MOD) % MOD;
    }
};