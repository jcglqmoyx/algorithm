#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper) {
        long long res = 0;
        int n = nums.size();

        auto get = [&](int limit) {
            long long res = 0;
            for (int i = 0, j = n - 1; i < j; i++) {
                while (j > i && nums[i] + nums[j] > limit) j--;
                res += j - i;
            }
            return res;
        };
        sort(nums.begin(), nums.end());
        return get(upper) - get(lower - 1);
    }
};