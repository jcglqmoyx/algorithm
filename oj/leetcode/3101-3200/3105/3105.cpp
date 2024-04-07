#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int> &nums) {
        int res = 1, n = nums.size();
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i + 1] == nums[i]) continue;
            bool inc = nums[i + 1] > nums[i];
            int j = i + 1;
            while (j < n && nums[j] != nums[j - 1] && nums[j] > nums[j - 1] == inc) j++;
            res = max(res, j - i);
            i = j - 2;
        }
        return res;
    }
};