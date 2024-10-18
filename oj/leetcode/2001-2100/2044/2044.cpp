#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int> &nums) {
        int max_or = 0;
        for (int x: nums) {
            max_or |= x;
        }
        int res = 0;
        auto dfs = [&](auto &&dfs, int u, int s) -> void {
            if (u == nums.size()) {
                if (s == max_or) res++;
            } else {
                dfs(dfs, u + 1, s | nums[u]);
                dfs(dfs, u + 1, s);
            }
        };
        dfs(dfs, 0, 0);
        return res;
    }
};