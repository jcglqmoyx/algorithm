#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int> &nums, int k) {
        if (k == 1) return nums;
        int n = nums.size();
        vector<int> res(n - k + 1);
        for (int idx = 0, cnt = 0, l = 0, r = 1; r < n; r++) {
            if (nums[r] == nums[r - 1] + 1) cnt++;
            if (r >= k - 1) {
                if (cnt == k - 1) {
                    res[idx++] = nums[r];
                } else {
                    res[idx++] = -1;
                }
                if (nums[l] + 1 == nums[l + 1]) cnt--;
                l++;
            }
        }
        return res;
    }
};