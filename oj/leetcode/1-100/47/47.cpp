#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<vector<int>> res;
        vector<bool> st(nums.size());
        auto dfs = [&](auto &&dfs, int u) -> void {
            if (u == nums.size()) {
                res.emplace_back(path);
            } else {
                for (int i = 0; i < nums.size(); i++) {
                    if (!st[i]) {
                        if (i && nums[i] == nums[i - 1] && !st[i - 1]) continue;
                        st[i] = true;
                        path.emplace_back(nums[i]);
                        dfs(dfs, u + 1);
                        path.pop_back();
                        st[i] = false;
                    }
                }
            }
        };
        dfs(dfs, 0);
        return res;
    }
};