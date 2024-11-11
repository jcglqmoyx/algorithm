#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minLengthAfterRemovals(vector<int> &nums) {
        int n = nums.size(), res = n;
        for (int l = 0, r = (n + 1) / 2; r < n; r++) {
            if (nums[r] > nums[l]) res -= 2, l++;
        }
        return res;
    }
};