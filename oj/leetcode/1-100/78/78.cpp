#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> path;
        vector<vector<int>> subsets;
        function<void(int)> dfs = [&](int u) {
            if (u == nums.size()) {
                subsets.emplace_back(path);
            } else {
                dfs(u + 1);

                path.emplace_back(nums[u]);
                dfs(u + 1);
                path.pop_back();
            }
        };
        dfs(0);
        return subsets;
    }
};