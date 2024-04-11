#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges) {
        auto n = nums.size();
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
        }
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        unordered_map<int, set<pair<int, int>>> map;
        vector<int> res(n, -1);
        function<void(int, int, int)> dfs = [&](int u, int p, int depth) {
            int max_depth = 0;
            for (int i = mn; i <= mx; i++) {
                if (gcd(i, nums[u]) == 1) {
                    if (!map[i].empty()) {
                        if (map[i].rbegin()->first > max_depth) {
                            max_depth = map[i].rbegin()->first;
                            res[u] = map[i].rbegin()->second;
                        }
                    }
                }
            }
            map[nums[u]].emplace(depth, u);
            for (int ne: g[u]) {
                if (ne != p) {
                    dfs(ne, u, depth + 1);
                }
            }
            map[nums[u]].erase(map[nums[u]].find({depth, u}));
        };
        dfs(0, -1, 1);
        return res;
    }
};