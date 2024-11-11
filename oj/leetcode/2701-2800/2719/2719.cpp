#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int memo[23][220];

int work(int n, int max_sum) {
    if (!n) return 1;
    max_sum = min(max_sum, n * 9);
    if (memo[n][max_sum] != -1) {
        return memo[n][max_sum];
    }
    int f[n + 1][max_sum + 1];
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(9, max_sum); j++) {
            for (int k = j; k <= max_sum; k++) {
                f[i][k] = (f[i][k] + f[i - 1][k - j]) % MOD;
            }
        }
    }
    int res = 0;
    for (int j = 0; j <= max_sum; j++) {
        res = (res + f[n][j]) % MOD;
    }
    memo[n][max_sum] = res;
    return res;
}

int f(string &num, int max_sum) {
    int n = static_cast<int>(num.size());
    int res = work(n - 1, max_sum);
    for (int i = 1; i <= n; i++) {
        int d = num[i - 1] - '0';
        for (int j = i == 1 ? 1 : 0; j < min(d, max_sum + 1); j++) {
            res = (res + work(n - i, max_sum - j)) % MOD;
        }
        max_sum -= d;
        if (max_sum < 0) break;
        if (i == n) res++;
    }
    return res;
}

int get(string &num, int min_sum, int max_sum) {
    return f(num, max_sum) - f(num, min_sum - 1);
}

class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(memo, -1, sizeof memo);
        int res = (get(num2, min_sum, max_sum) - get(num1, min_sum, max_sum) + MOD) % MOD;
        int sum = 0;
        for (char c: num1) {
            sum += c - '0';
        }
        if (sum >= min_sum && sum <= max_sum) {
            res++;
        }
        return (res + MOD) % MOD;
    }
};