#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        auto n = height.size();
        int res = 0;
        for (int max_l = 0, max_r = 0, i = 0, j = n - 1; i < j;) {
            max_l = max(max_l, height[i]);
            max_r = max(max_r, height[j]);
            res = max(res, (j - i) * min(max_l, max_r));
            if (height[i] < height[j]) i++;
            else j--;
        }
        return res;
    }
};