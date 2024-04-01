#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countAlternatingSubarrays(vector<int> &nums) {
        long long res = 0;
        for (int l = 0, r = 1; l < nums.size(); l++) {
            r = max(r, l + 1);
            while (r < nums.size() && nums[r] - nums[r - 1]) r++;
            res += r - l;
        }
        return res;
    }
};