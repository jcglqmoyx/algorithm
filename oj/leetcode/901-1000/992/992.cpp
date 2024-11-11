#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int subarraysWithKDistinct(const vector<int> &nums, int k) {
        int res = 0;
        const auto n = nums.size();
        int l[n + 1], r[n + 1];
        memset(l, 0, sizeof l), memset(r, 0, sizeof r);
        for (int li = 0, ri = 0, j = 0, ci = 0, cj = 0; j < n; j++) {
            l[nums[j]]++, r[nums[j]]++;
            if (l[nums[j]] == 1) ci++;
            if (r[nums[j]] == 1) cj++;
            while (cj == k) {
                r[nums[ri]]--;
                if (r[nums[ri]] == 0) cj--;
                ri++;
            }
            while (ci > k) {
                l[nums[li]]--;
                if (l[nums[li]] == 0) ci--;
                li++;
            }
            res += ri - li;
        }
        return res;
    }
};
