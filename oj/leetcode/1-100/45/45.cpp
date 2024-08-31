#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int res = 0, r = 0, max_r = 0, n = nums.size();
        for (int i = 0; i + 1 < n; i++) {
            max_r = max(max_r, i + nums[i]);
            if (i == r) {
                r = max(r, max_r);
                res++;
            }
        }
        return res;
    }
};