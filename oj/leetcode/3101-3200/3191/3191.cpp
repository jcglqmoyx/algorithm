#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i + 2 < n; i++) {
            if (nums[i] == 0) {
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                res++;
            }
        }
        if (nums[n - 1] == 0 || nums[n - 2] == 0) return -1;
        return res;
    }
};