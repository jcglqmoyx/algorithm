#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long findKthSmallest(vector<int> &coins, int k) {
        using ll = long long;
        ll r = *min_element(coins.begin(), coins.end()) * 1LL * k;
        vector<pair<ll, ll>> t;
        unordered_map<ll, ll> memo;
        for (int x: coins) {
            t.reserve(memo.size());
            for (auto &[a, c]: memo) {
                long long a0 = lcm(a, x);
                if (a0 <= r) t.emplace_back(a0, -c);
            }
            for (auto &[a, c]: t) {
                memo[a] += c;
            }
            t.clear();
            memo[x]++;
        }

        auto check = [&](ll mid) {
            ll cnt = 0;
            for (auto &[a, c]: memo) {
                cnt += c * mid / a;
            }
            return cnt >= k;
        };
        ll l = k;
        while (l < r) {
            ll mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};