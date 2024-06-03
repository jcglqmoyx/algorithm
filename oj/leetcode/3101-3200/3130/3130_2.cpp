#include <bits/stdc++.h>

using namespace std;


const int MOD = 1'000'000'007;
const int MX = 1001;

long long F[MX];
long long INV_F[MX];

long long pow(long long x, int n) {
    long long res = 1;
    for (; n; n /= 2) {
        if (n % 2) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
    }
    return res;
}

auto init = [] {
    F[0] = 1;
    for (int i = 1; i < MX; i++) {
        F[i] = F[i - 1] * i % MOD;
    }

    INV_F[MX - 1] = pow(F[MX - 1], MOD - 2);
    for (int i = MX - 1; i; i--) {
        INV_F[i - 1] = INV_F[i] * i % MOD;
    }
    return 0;
}();

long long comb(int n, int m) {
    return F[n] * INV_F[m] % MOD * INV_F[n - m] % MOD;
}

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        if (zero > one) {
            swap(zero, one);
        }
        vector<long long> f0(zero + 3);
        for (int i = (zero - 1) / limit + 1; i <= zero; i++) {
            f0[i] = comb(zero - 1, i - 1);
            for (int j = 1; j <= (zero - i) / limit; j++) {
                f0[i] = (f0[i] + (1 - j % 2 * 2) * comb(i, j) * comb(zero - j * limit - 1, i - 1)) % MOD;
            }
        }

        long long ans = 0;
        for (int i = (one - 1) / limit + 1; i <= min(one, zero + 1); i++) {
            long long f1 = comb(one - 1, i - 1);
            for (int j = 1; j <= (one - i) / limit; j++) {
                f1 = (f1 + (1 - j % 2 * 2) * comb(i, j) * comb(one - j * limit - 1, i - 1)) % MOD;
            }
            ans = (ans + (f0[i - 1] + f0[i] * 2 + f0[i + 1]) * f1) % MOD;
        }
        return (ans + MOD) % MOD;
    }
};