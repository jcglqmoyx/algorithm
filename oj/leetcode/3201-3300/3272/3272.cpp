#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        using ll = long long;
        ll res = 0, a[11];
        a[0] = 1;
        for (int i = 1; i <= 10; i++) a[i] = a[i - 1] * i;
        unordered_set<ll> S;
        for (int i = pow(10, (n - 1) / 2); i < pow(10, (n - 1) / 2 + 1); i++) {
            ll x = i, temp = i;
            if (n & 1) temp /= 10;
            while (temp) {
                x = x * 10 + temp % 10;
                temp /= 10;
            }
            if (x % k == 0) {
                int d[10]{};
                while (x) {
                    d[x % 10]++;
                    x /= 10;
                }
                ll t = 0;
                for (int u = 9; u >= 0; u--) {
                    for (int i = d[u]; i; i--) {
                        t = t * 10 + u;
                    }
                }
                if (S.contains(t)) continue;
                S.emplace(t);
                ll s = (n - d[0]) * a[n - 1];
                for (int u = 0; u <= 9; u++) {
                    if (a[d[u]]) s /= a[d[u]];
                }
                res += s;
            }
        }
        return res;
    }
};