const int MOD = 1e9 + 7;

const int N = 2000;

int fact[N];
int inv_fact[N];

int power(long long x, int a) {
    long long res = 1;
    while (a) {
        if (a & 1) res = res * x % MOD;
        x = x * x % MOD;
        a >>= 1;
    }
    return (int) res;
}

int init = []() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (int) ((long long) fact[i - 1] * i % MOD);
    }
    inv_fact[N - 1] = power(fact[N - 1], MOD - 2);
    for (int i = N - 1; i; i--) {
        inv_fact[i - 1] = (int) ((long long) inv_fact[i] * i % MOD);
    }
    return 0;
}();

class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        return (int) ((long long) fact[n + k - 1] * inv_fact[n - 1] % MOD * inv_fact[k] % MOD);
    }
};