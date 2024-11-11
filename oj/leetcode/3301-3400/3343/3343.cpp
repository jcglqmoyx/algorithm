#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

const int N = 85;

int fact[N];
int inv_fact[N];

int pow(int x, int n) {
    long long res = 1;
    while (n) {
        if (n & 1) {
            res = res * x % MOD;
        }
        x = (long long) x * x % MOD;
        n >>= 1;
    }
    return res;
}

int init = []() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (long long) fact[i - 1] * i % MOD;
        inv_fact[i] = pow(fact[i], MOD - 2);
    }
    return 0;
}();


class Solution {
public:
    int countBalancedPermutations(string num) {
        int cnt[10]{};
        int n = static_cast<int>(num.size()), s = 0;
        for (char c: num) {
            int u = c - '0';
            s += u;
            cnt[u]++;
        }
        if (s & 1) {
            return 0;
        }
        int m = n / 2, half = s / 2;
        int f[m + 1][half + 1];
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (char c: num) {
            int u = c - '0';
            for (int j = m; j; j--) {
                for (int k = half; k >= u; k--) {
                    f[j][k] = (f[j][k] + f[j - 1][k - u]) % MOD;
                }
            }
        }
        long long res = f[m][half];
        res = res * fact[m] % MOD;
        res = res * fact[n - m] % MOD;
        for (int i = 0; i <= 9; i++) {
            res = res * inv_fact[cnt[i]] % MOD;
        }
        return res;
    }
};