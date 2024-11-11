#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumTotalCost(vector<int> &nums) {
        long long a = 0, b = INT64_MIN;
        for (int i = 0; i < nums.size(); i++) {
            long long t = max(a, b) + nums[i];
            b = INT64_MIN;
            if (i) b = a - nums[i];
            a = t;
        }
        return max(a, b);
    }
};