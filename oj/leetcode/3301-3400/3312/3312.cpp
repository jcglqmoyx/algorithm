#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int> &nums, vector<long long> &queries) {
        int mx = *max_element(nums.begin(), nums.end());
        int cnt[mx + 1];
        memset(cnt, 0, sizeof cnt);
        for (int x: nums) cnt[x]++;
        long long cnt_gcd[mx + 1];
        memset(cnt_gcd, 0, sizeof cnt_gcd);
        for (int i = mx; i >= 1; i--) {
            int c = 0;
            for (int j = i; j <= mx; j += i) {
                c += cnt[j];
                cnt_gcd[i] -= cnt_gcd[j];
            }
            cnt_gcd[i] += c * (c - 1LL) / 2;
        }
        partial_sum(cnt_gcd, cnt_gcd + mx + 1, cnt_gcd);
        auto n = queries.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = upper_bound(cnt_gcd, cnt_gcd + mx, queries[i]) - cnt_gcd;
        }
        return res;
    }
};