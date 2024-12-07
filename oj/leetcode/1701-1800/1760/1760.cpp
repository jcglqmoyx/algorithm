#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSize(vector<int> &nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = (l + r) >> 1;
            int op = maxOperations;
            for (int x: nums) {
                op -= (x - 1) / mid;
            }
            if (op >= 0) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};