#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int MOD = 1e9 + 7;

const int N = 100010;

LL fact[N], inv_fact[N];

LL power(int x, int a) {
    LL res = 1;
    while (a) {
        if (a & 1) res = res * x % MOD;
        x = (LL) x * x % MOD;
        a >>= 1;
    }
    return res;
}


auto init = [] {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[N - 1] = power(fact[N - 1], MOD - 2);
    for (int i = N - 1; i > 0; i--) {
        inv_fact[i - 1] = inv_fact[i] * i % MOD;
    }
    return 0;
}();

class Solution {
public:
    int numberOfSequence(int n, vector<int> &sick) {
        int res = 1, tot = n - sick.size(), e = 0;
        for (int last = 0, i = 0; i < sick.size(); i++) {
            if (sick[i] > last) {
                int len = sick[i] - last;
                e += last == 0 ? 0 : len - 1;
                res = res * fact[tot] % MOD * inv_fact[len] % MOD * inv_fact[tot - len] % MOD;
                tot -= len;
            }
            last = sick[i] + 1;
        }
        return res * power(2, e) % MOD;
    }
};