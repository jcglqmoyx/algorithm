#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get_min(vector<int> &nums) {
        int mn = 1e9;
        for (int x: nums) {
            mn = min(mn, x);
        }
        return mn;
    }

public:
    int addedInteger(vector<int> &nums1, vector<int> &nums2) {
        return get_min(nums2) - get_min(nums1);
    }
};