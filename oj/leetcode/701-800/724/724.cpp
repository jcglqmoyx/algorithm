#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int s = 0;
        for (int x: nums) {
            s += x;
        }
        for (int left = 0, right = s - nums[0], i = 0; i < nums.size(); i++) {
            if (left == right) return i;
            left += nums[i];
            if (i + 1 < nums.size()) {
                right -= nums[i + 1];
            }
        }
        return -1;
    }
};