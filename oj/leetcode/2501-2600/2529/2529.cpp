#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int> &nums) {
        auto helper = [&](int x) {
            return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
        };
        return max(helper(0), (long) nums.size() - helper(1));
    }
};