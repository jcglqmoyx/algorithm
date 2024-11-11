class Solution {
    static constexpr long long MOD = 1e9 + 7;

    static long long pow(long long x, int n) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
        }
        return res;
    }

public:
    int stringCount(int n) {
        return (int) (((pow(26, n)
                        - pow(25, n - 1) * (75 + n)
                        + pow(24, n - 1) * (72 + n * 2)
                        - pow(23, n - 1) * (23 + n)) % MOD + MOD) % MOD);
    }
};