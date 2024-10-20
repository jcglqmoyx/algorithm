#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int MOD = 1e9 + 7;

int s[N];
int memo[10][101];

int init = []() {
    memset(memo, -1, sizeof memo);

    int f[10];
    f[0] = 0;
    fill(f + 1, f + 10, 1);
    s[1] = 9;
    for (int i = 2; i < N; i++) {
        s[i] += s[i - 1];
        int g[10];
        memset(g, 0, sizeof g);
        for (int j = 0; j <= 9; j++) {
            if (j) g[j] = f[j - 1];
            if (j < 9) g[j] = (g[j] + f[j + 1]) % MOD;
            s[i] = (s[i] + g[j]) % MOD;
        }
        memcpy(f, g, sizeof g);
    }
    return 0;
}();

int helper(int start, int n) {
    if (!n) return 1;
    if (memo[start][n] != -1) return memo[start][n];
    int f[10];
    memset(f, 0, sizeof f);
    f[start] = 1;
    for (int i = 1; i <= n; i++) {
        int g[10];
        memset(g, 0, sizeof g);
        for (int j = 0; j <= 9; j++) {
            if (j) g[j] = f[j - 1];
            if (j < 9) g[j] = (g[j] + f[j + 1]) % MOD;
        }
        memcpy(f, g, sizeof g);
    }
    int res = 0;
    for (int j = 0; j <= 9; j++) {
        res = (res + f[j]) % MOD;
    }
    memo[start][n] = res;
    return res;
}

int get(string &limit) {
    auto n = limit.size();
    int res = n > 1 ? s[n - 1] : 0;
    for (int i = 1, prev = -1; i <= n; i++) {
        int d = limit[i - 1] - '0';
        if (i == 1) {
            for (int j = 1; j < d; j++) {
                res = (res + helper(j, n - i)) % MOD;
            }
        } else {
            for (int j: {prev - 1, prev + 1}) {
                if (j >= 0 && j < d) res = (res + helper(j, n - i)) % MOD;
            }
        }
        if (i > 1 && abs(d - prev) != 1) break;
        if (i == n) res = (res + 1) % MOD;
        prev = d;
    }
    return res;
}

class Solution {
public:
    int countSteppingNumbers(string low, string high) {
        int res = (get(high) - get(low) + MOD) % MOD;
        int t = 1;
        for (int i = 1; i < low.size(); i++) {
            if (abs(low[i] - low[i - 1]) != 1) {
                t = 0;
                break;
            }
        }
        res = (res + t) % MOD;
        return res;
    }
};