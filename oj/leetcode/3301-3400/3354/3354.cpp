#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countValidSelections(vector<int> &nums) {
        int n = static_cast<int>(nums.size()), res = 0;
        int suf = accumulate(nums.begin(), nums.end(), 0);
        for (int pre = 0, i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (pre == suf) {
                    res += 2;
                } else if (pre == suf + 1 || suf == pre + 1) {
                    res++;
                }
            } else {
                pre += nums[i];
                suf -= nums[i];
            }
        }
        return res;
    }
};