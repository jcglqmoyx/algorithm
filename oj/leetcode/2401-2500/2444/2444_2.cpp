#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK) {
        long long res = 0;
        for (int l = -1, a = -1, b = -1, i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (x < minK || x > maxK) {
                l = i;
            } else {
                if (x == minK) a = i;
                if (x == maxK) b = i;
            }
            res += max(min(a, b) - l, 0);
        }
        return res;
    }
};