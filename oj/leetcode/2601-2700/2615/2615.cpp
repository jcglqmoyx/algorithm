#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int> &nums) {
        using ll = long long;
        unordered_map<int, vector<int>> map;
        for (size_t i = 0; i < nums.size(); i++) {
            map[nums[i]].emplace_back(i);
        }
        vector<ll> res(nums.size());
        for (auto &[k, v]: map) {
            ll l = 0, r = 0;
            int n = v.size();
            for (int x: v) r += x;
            for (int i = 0; i < n; i++) {
                l += v[i], r -= v[i];
                res[v[i]] = v[i] * (i + 1LL) - l + r - v[i] * (n - i - 1LL);
            }
        }
        return res;
    }
};