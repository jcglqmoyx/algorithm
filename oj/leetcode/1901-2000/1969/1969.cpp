#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int MOD = 1e9 + 7;

LL power(LL x, LL n) {
    LL res = 1;
    while (n) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

class Solution {
public:
    int minNonZeroProduct(int p) {
        return ((1LL << p) - 1) % MOD * power(((1LL << p) - 2) % MOD, (1LL << p) - 2 >> 1) % MOD;
    }
};
