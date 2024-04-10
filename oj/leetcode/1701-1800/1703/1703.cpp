#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves(vector<int> &nums, int k) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                nums[cnt] = i - cnt;
                cnt++;
            }
        }
        if (cnt == nums.size()) return 0;
        int res = INT32_MAX;
        int l = 0, s = 0;
        for (int i = 0; i < cnt; i++) {
            if (i >= k / 2) l += nums[i - k / 2];
            s += nums[i];
            if (i >= k - 1) {
//                res = min(res, s - l - nums[i - k / 2] * (k - (k + 1) / 2) + ((k + 1) / 2) * nums[i - k / 2] - l);
                res = min(res, s - l * 2 + nums[i - k / 2] * (k & 1 ? 1 : 0));
                l -= nums[i - k + 1];
                s -= nums[i - k + 1];
            }
        }
        return res;
    }
};