#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long sumDigitDifferences(vector<int> &nums) {
        long long n = nums.size(), m = to_string(nums[0]).length();
        long long ans = m * n * (n - 1) / 2;
        vector<array<int, 10>> cnt(m);
        for (int x: nums) {
            for (int i = 0; x; x /= 10) {
                ans -= cnt[i++][x % 10]++;
            }
        }
        return ans;
    }
};