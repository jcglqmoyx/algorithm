#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int M = 1e9 + 7;

ll power(ll a, int n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * a % M;
        a = a * a % M;
        n >>= 1;
    }
    return res;
}

class Solution {
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier) {
        if (multiplier == 1) return nums;
        ll mul = multiplier;
        int n = nums.size(), mx = 0;
        set<pair<ll, int>> s;
        for (int i = 0; i < n; i++) {
            s.emplace(nums[i], i);
            mx = max(mx, nums[i]);
        }
        int op = 0;
        while (op < k) {
            ll mn = s.begin()->first, idx = s.begin()->second;
            s.erase(s.begin());
            if (mn * mul <= mx) {
                mn *= mul;
                op++;
                s.emplace(mn, idx);
            } else {
                s.emplace(mn, idx);
                break;
            }
        }
        for (auto it: s) {
            nums[it.second] = it.first % M;
        }
        k -= op;
        if (!k) return nums;
        int round = k / n;
        for (int &num: nums) {
            num = num * power(mul, round) % M;
        }
        k %= n;
        while (k--) {
            auto idx = s.begin()->second;
            s.erase(s.begin());
            nums[idx] = nums[idx] * mul % M;
        }
        return nums;
    }
};