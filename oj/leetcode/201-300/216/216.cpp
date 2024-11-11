#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        vector<vector<int>> res;
        function<void(int, int, int)> dfs = [&](int u, int cnt, int sum) {
            if (cnt > k || sum > n) return;
            if (u == 10) {
                if (cnt == k && sum == n) res.emplace_back(v);
                return;
            }
            dfs(u + 1, cnt, sum);
            v.emplace_back(u);
            dfs(u + 1, cnt + 1, sum + u);
            v.pop_back();
        };
        dfs(1, 0, 0);
        return res;
    }
};