#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double minimumAverage(vector<int> &nums) {
        double res = 1e9;
        sort(nums.begin(), nums.end());
        for (int i = 0, j = nums.size() - 1; i < j; i++, j--) {
            res = min(res, (nums[i] + nums[j]) * 1.0 / 2);
        }
        return res;
    }
};