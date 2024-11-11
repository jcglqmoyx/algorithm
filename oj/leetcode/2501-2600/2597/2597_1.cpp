#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int> &nums, int k) {
        int res = 0;
        sort(nums.begin(), nums.end());
        bool st[1001];
        function<void(int)> dfs = [&](int u) {
            if (u == nums.size()) {
                res++;
            } else {
                dfs(u + 1);
                if (nums[u] - k < 1 || !st[nums[u] - k]) {
                    st[nums[u]] = true;
                    dfs(u + 1);
                    st[nums[u]] = false;
                }
            }
        };
        dfs(0);
        return res - 1;
    }
};