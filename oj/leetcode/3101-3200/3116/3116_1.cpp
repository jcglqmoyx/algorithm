#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long findKthSmallest(vector<int> &coins, int k) {
        using ll = long long;
        auto n = coins.size();
        auto check = [&](ll mid) {
            ll cnt = 0;
            for (int i = 1; i < 1 << n; i++) {
                ll x = 1;
                for (int j = 0; j < n; j++) {
                    if (i >> j & 1) {
                        x = lcm(x, coins[j]);
                        if (x > mid) break;
                    }
                }
                cnt += (__builtin_popcount(i) & 1 ? 1 : -1) * mid / x;
            }
            return cnt >= k;
        };
        ll l = k, r = *min_element(coins.begin(), coins.end()) * 1LL * k;
        while (l < r) {
            ll mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};