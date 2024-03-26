#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>&nums) {
        int n = nums.size();
        for (int&x: nums) {
            if (x <= 0) x = n + 1;
        }
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            x = abs(x);
            if (x <= n && nums[x - 1] > 0) {
                nums[x - 1] = -nums[x - 1];
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};
