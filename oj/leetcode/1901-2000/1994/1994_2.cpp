#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long power(long long x, int n) {
    long long res = 1;
    while (n) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

vector<vector<int>> factor(31);

int init = []() {
    for (int i = 2; i <= 30; i++) {
        int x = i;
        bool ok = true;
        for (int a = 2; a * a <= x; a++) {
            if (x % a == 0) {
                if (x % (a * a) == 0) {
                    ok = false;
                    break;
                }
                factor[i].emplace_back(a);
                x /= a;
            }
        }
        if (ok) {
            if (x > 1) {
                factor[i].emplace_back(x);
            }
        } else {
            factor[i].clear();
        }
    }
    return 0;
}();


class Solution {
public:
    int numberOfGoodSubsets(vector<int> &nums) {
        int cnt[31]{};
        for (int x: nums) {
            cnt[x]++;
        }
        int v[30], n = 0;
        for (int i = 2; i <= 30; i++) {
            if (cnt[i] && !factor[i].empty()) v[n++] = i;
        }
        for (int i = 0; i < n; i++) cout << v[i] << endl;
        long long res = 0;
        int f[1 << n];
        memset(f, 0, sizeof f);
        for (int i = 1; i < 1 << n; i++) {
            int x = i & -i;
            if (x == i) {
                f[i] = cnt[v[__builtin_ctz(x)]];
            } else {
                int st = 0;
                bool ok = true;
                for (int j = 0; j < n; j++) {
                    if (i >> j & 1) {
                        for (int a: factor[v[j]]) {
                            if (st >> a & 1) {
                                ok = false;
                                break;
                            }
                            st |= 1 << a;
                        }
                    }
                    if (!ok) break;
                }
                if (ok) {
                    f[i] = (long long) f[i ^ x] * f[x] % MOD;
                }
            }
            res = (res + f[i]) % MOD;
        }
        return res * power(2, cnt[1]) % MOD;
    }
};