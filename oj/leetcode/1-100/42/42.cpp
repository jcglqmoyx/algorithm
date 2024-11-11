#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int l = 0, r = height.size() - 1;
        int max_l = height[l], max_r = height[r];
        int res = 0;
        while (l < r) {
            if (max_l < max_r) {
                res += max(0, max_l - height[l]);
                l++;
                max_l = max(max_l, height[l]);
            } else {
                res += max(0, max_r - height[r]);
                r--;
                max_r = max(max_r, height[r]);
            }
        }
        return res;
    }
};