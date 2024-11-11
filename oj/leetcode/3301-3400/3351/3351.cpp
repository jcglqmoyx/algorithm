#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfGoodSubsequences(vector<int> &nums) {
        const int MOD = 1'000'000'007;
        unordered_map<int, int> f, cnt;
        for (int x: nums) {
            long long c = cnt[x - 1] + cnt[x + 1] + 1;
            f[x] = (x * c + f[x] + f[x - 1] + f[x + 1]) % MOD;
            cnt[x] = (cnt[x] + c) % MOD;
        }

        long long ans = 0;
        for (const auto &[_, s]: f) {
            ans += s;
        }
        return ans % MOD;
    }
};