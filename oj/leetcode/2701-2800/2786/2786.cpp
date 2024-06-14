#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxScore(vector<int> &nums, int x) {
        long long o = INT64_MIN / 2, e = INT64_MIN / 2;
        if (nums[0] & 1) o = nums[0];
        else e = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] & 1) {
                o = max(o, e - x) + nums[i];
            } else {
                e = max(e, o - x) + nums[i];
            }
        }
        return max(o, e);
    }
};