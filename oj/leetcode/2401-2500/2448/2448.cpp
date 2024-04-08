#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minCost(vector<int> &nums, vector<int> &cost) {
        auto n = nums.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) v[i] = {nums[i], cost[i]};
        sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.first < b.first;
        });
        long long l = 0, r = 0, lc = v[0].second, rc = 0;
        for (int i = 1; i < n; i++) r += (v[i].first - v[0].first) * 1LL * v[i].second, rc += v[i].second;
        long long res = r;
        for (int i = 1; i < n; i++) {
            long long diff = v[i].first - v[i - 1].first;
            l += diff * lc, lc += v[i].second;
            r -= diff * rc, rc -= v[i].second;
            res = min(res, l + r);
        }
        return res;
    }
};