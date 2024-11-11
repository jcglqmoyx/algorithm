#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges) {
        long long f0 = 0, f1 = INT64_MIN / 2;
        for (int x: nums) {
            long long g0 = max(f0 + x, f1 + (x ^ k));
            long long g1 = max(f0 + (x ^ k), f1 + x);
            f0 = g0, f1 = g1;
        }
        return f0;
    }
};
