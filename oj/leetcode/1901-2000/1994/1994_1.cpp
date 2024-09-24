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
        long long res = 0;
        for (int i = 1; i < 1 << n; i++) {
            long long t = 1;
            bool st[30]{}, ok = true;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    for (int f: factor[v[j]]) {
                        if (st[f]) {
                            ok = false;
                            break;
                        }
                        st[f] = true;
                    }
                    t = t * cnt[v[j]] % MOD;
                }
                if (!ok) break;
            }
            if (ok) res = (res + t) % MOD;
        }
        return res * power(2, cnt[1]) % MOD;
    }
};