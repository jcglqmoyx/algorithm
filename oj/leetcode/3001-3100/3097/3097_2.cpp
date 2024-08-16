#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int> &nums, int k) {
        if (!k) return 1;
        int n = nums.size();
        int s1[n + 1], s2[n + 1], idx1 = 0, idx2 = 0;
        s1[0] = s2[0] = 0;
        int res = n + 1;
        for (int i = 0; i < n; i++) {
            s2[idx2 + 1] = s2[idx2] | nums[i];
            idx2++;
            while ((s1[idx1] | s2[idx2]) >= k) {
                res = min(res, idx1 + idx2);
                if (!idx1) {
                    for (int j = 1; j <= idx2; j++) {
                        s1[j] = s1[j - 1] | nums[i - j + 1];
                    }
                    idx1 = idx2;
                    idx2 = 0;
                }
                idx1--;
            }
        }
        return res == n + 1 ? -1 : res;
    }
};