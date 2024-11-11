#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> v;
        auto dfs = [&](auto &&dfs, int u, int sum) {
            if (u == candidates.size()) {
                if (sum == target) {
                    res.emplace_back(v);
                }
                return;
            }
            if (sum + candidates[u] <= target) {
                v.emplace_back(candidates[u]);
                dfs(dfs, u, sum + candidates[u]);
                v.pop_back();
            }
            dfs(dfs, u + 1, sum);
        };
        dfs(dfs, 0, 0);
        return res;
    }
};