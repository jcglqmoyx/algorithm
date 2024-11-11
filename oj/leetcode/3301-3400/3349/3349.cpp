#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int> &nums, int k) {
        int last_len = 0, idx = -1;
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            while (j < nums.size() && nums[j] > nums[j - 1]) j++;
            int len = j - i;
            if (last_len >= k && len >= k && idx == i - 1 || len >= k * 2) {
                return true;
            }
            last_len = j - i;
            idx = j - 1;
            i = j - 1;
        }
        return false;
    }
};