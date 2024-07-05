#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests) {
        auto n = nums.size();
        int d[n + 2], m = 1e9 + 7;
        memset(d, 0, sizeof d);
        for (auto &r: requests) {
            d[r[0]]++;
            d[r[1] + 1]--;
        }
        for (int i = 1; i < n; i++) {
            d[i] += d[i - 1];
        }
        sort(d, d + n, greater<>());
        int res = 0;
        sort(nums.begin(), nums.end(), greater<>());
        for (int i = 0; i < n; i++) {
            res = (int) ((res + (long long) d[i] * nums[i]) % m);
        }
        return res;
    }
};