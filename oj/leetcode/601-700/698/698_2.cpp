#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if (tot % k) {
            return false;
        }

        int sub = tot / k;

        sort(nums.begin(), nums.end(), greater<>());
        if (nums[0] > sub) {
            return false;
        }

        auto n = nums.size();
        bool st[n];
        memset(st, 0, sizeof st);
        auto dfs = [&](auto &&dfs, int start, int cur, int need) {
            if (!need) return true;
            if (cur == sub) return dfs(dfs, 0, 0, need - 1);
            for (int i = start; i < n; i++) {
                if (!st[i] && cur + nums[i] <= sub) {
                    st[i] = true;
                    if (dfs(dfs, i + 1, cur + nums[i], need)) {
                        return true;
                    }
                    st[i] = false;
                    while (i + 1 < n && nums[i + 1] == nums[i]) i++;
                    if (!cur || cur + nums[i] == sub) break;
                }
            }
            return false;
        };
        return dfs(dfs, 0, 0, k);
    }
};