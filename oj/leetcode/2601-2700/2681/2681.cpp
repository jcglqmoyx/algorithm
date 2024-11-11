#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfPower(vector<int> &nums) {
        int m = 1e9 + 7, res = 0;
        sort(nums.begin(), nums.end());
        long long s = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long x = nums[i];
            long long sq = x * x % m;
            s = (s * 2 + x) % m;
            res = (res + sq * s) % m;
        }
        return res;
    }
};