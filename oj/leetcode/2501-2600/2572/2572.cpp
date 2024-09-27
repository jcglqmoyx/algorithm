#include <bits/stdc++.h>

using namespace std;

int m = 1e9 + 7;

int v[30];

long long power(long long x, int n) {
    long long res = 1;
    while (n) {
        if (n & 1) res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
};

class Solution {
public:
    int squareFreeSubsets(vector<int> &nums) {
        int cnt[31]{}, n = 0;
        for (int x: nums) {
            cnt[x]++;
        }
        int cnt1 = cnt[1];
        cnt[1] = cnt[4] = cnt[8] = cnt[9] = cnt[12] = cnt[16] = cnt[18] = cnt[20] = cnt[24] = cnt[27] = cnt[28] = 0;
        for (int i = 1; i <= 30; i++) {
            if (cnt[i]) {
                v[n++] = i;
            }
        }
        int factors[1 << n], f[1 << n], res = 0;
        memset(factors, -1, sizeof factors);
        memset(f, 0, sizeof f);
        factors[0] = 0, f[0] = 1;
        for (int i = 1; i < 1 << n; i++) {
            int r = i & -i;
            int l = i ^ r;
            if (factors[i ^ r] == -1) continue;
            int u = __builtin_ctz(r);
            int x = v[u];
            factors[i] = factors[l];
            for (int j = 2; j * j <= x; j++) {
                if (x % j == 0) {
                    if (factors[i] >> j & 1) {
                        factors[i] = -1;
                        break;
                    }
                    factors[i] |= 1 << j;
                    x /= j;
                }
            }
            if (factors[i] == -1) continue;
            if (x > 1) {
                if (factors[i] >> x & 1) {
                    continue;
                }
                factors[i] |= 1 << x;
            }
            f[i] = (long long) f[l] * cnt[v[u]] % m;
            res = (res + f[i]) % m;
        }
        if (cnt1) {
            if (!res) res = (power(2, cnt1) - 1 + m) % m;
            else res = (res * power(2, cnt1) % m + (power(2, cnt1) - 1 + m)) % m;
        }
        return res;
    }
};