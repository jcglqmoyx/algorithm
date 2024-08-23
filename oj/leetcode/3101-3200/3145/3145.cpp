#include <bits/stdc++.h>

using namespace std;

class Solution {
    using ll = long long;

    int power(ll x, ll n, int mod) {
        ll res = 1;
        while (n) {
            if (n & 1) res = res * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }

    // the number of bits in the range[1, x]
    vector<ll> get(ll x) {
        ll temp = x;
        vector<int> v;
        while (temp) {
            v.emplace_back(temp & 1);
            temp >>= 1;
        }
        int n = v.size();
        vector<ll> res(50);
        if (x == 0) return res;
        reverse(v.begin(), v.end());
        ll left = 0;
        ll right[n + 1];
        right[n] = 0;
        for (int i = n - 1; i > 0; i--) {
            right[i] = v[i] * (1LL << (n - i - 1)) + right[i + 1];
        }
        for (int i = 0; i < n; i++) {
            int u = x >> (n - i - 1) & 1;
            res[n - i - 1] += left * (1LL << (n - i - 1));
            if (u) {
                res[n - i - 1] += right[i + 1] + 1;
            }
            left = left * 2 + v[i];
        }
        return res;
    }

public:
    vector<int> findProductsOfElements(vector<vector<long long>> &queries) {
        auto m = queries.size();
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            ll from = queries[i][0], to = queries[i][1] + 1, mod = queries[i][2];
            ll l = 0, r = to;
            while (l < r) {
                ll mid = (l + r + 1) >> 1;
                auto t = get(mid);
                if (accumulate(t.begin(), t.end(), 0LL) <= to) l = mid;
                else r = mid - 1;
            }
            auto t = get(l);
            ll tot = accumulate(t.begin(), t.end(), 0LL);
            for (int u = 0; u < 50 && to > tot; u++) {
                if ((l + 1) >> u & 1) {
                    t[u]++;
                    to--;
                }
            }
            l = 0, r = from;
            while (l < r) {
                ll mid = (l + r + 1) >> 1;
                auto t = get(mid);
                if (accumulate(t.begin(), t.end(), 0LL) <= from) l = mid;
                else r = mid - 1;
            }

            auto s = get(l);
            for (int u = 0; u < 50; u++) {
                t[u] -= s[u];
            }
            tot = accumulate(s.begin(), s.end(), 0LL);
            for (int u = 0; u < 50 && from > tot; u++) {
                if ((l + 1) >> u & 1) {
                    t[u]--;
                    from--;
                }
            }
            ll p = 1;
            for (int u = 0; u < 50; u++) {
                if (t[u]) {
                    p = p * power((1LL << u) % mod, t[u], mod) % mod;
                }
            }
            res[i] = p;
        }
        return res;
    }
};