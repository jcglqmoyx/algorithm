#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countWays(vector<int> &nums) {
        int n = nums.size(), cnt[n];
        memset(cnt, 0, sizeof cnt);
        for (int x: nums) {
            cnt[x]++;
        }
        for (int u = 0, i = 0; i < n; i++) {
            while (cnt[i]--) {
                nums[u++] = i;
            }
        }
        int res = (nums[0] > 0) + (nums[n - 1] < n);
        for (int i = 0; i + 1 < n; i++) {
            res += (nums[i] < i + 1 && nums[i + 1] > i + 1);
        }
        return res;
    }
};