#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int> &nums) {
        int res = 0;
        int last_len = 0, last_idx = -1;
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            while (j < nums.size() && nums[j] > nums[j - 1]) j++;
            int len = j - i;
            if (last_idx == i - 1) {
                res = max({res, len / 2, min(last_len, len)});
            }
            last_len = len, last_idx = j - 1;
            i = j - 1;
        }
        return res;
    }
};