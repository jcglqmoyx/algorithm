#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int res = 0;
        for (int r = 0, max_r = 0, i = 0; i + 1 < nums.size(); i++) {
            max_r = max(max_r, i + nums[i]);
            if (i == r) {
                r = max(r, max_r);
                res++;
            }
        }
        return res;
    }
};