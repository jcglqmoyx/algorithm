#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        using ll = long long;

        auto get = [&](ll mid) {
            ll cnt = 0;
            vector<int> v;
            while (mid) {
                v.emplace_back(mid & 1);
                mid >>= 1;
            }
            int n = v.size();
            for (int i = x - 1; i < n; i += x) {
                ll right = 0;
                for (int j = n - 1; j > i; j--) right = right * 2 + v[j];
                cnt += right * (1LL << i);
                if (v[i]) {
                    ll left = 0;
                    for (int j = i - 1; j >= 0; j--) {
                        left = left * 2 + v[j];
                    }
                    cnt += left + 1;
                }
            }
            return cnt;
        };

        ll l = 1, r = k << x;
        while (l < r) {
            ll mid = (l + r + 1) >> 1;
            if (get(mid) <= k) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};