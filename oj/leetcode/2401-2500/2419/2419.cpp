#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums) {
        int mx = *max_element(nums.begin(), nums.end()), res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == mx) {
                int j = i + 1;
                while (j < nums.size() && nums[j] == mx) j++;
                res = max(res, j - i);
                i = j - 1;
            }
        }
        return res;
    }
};