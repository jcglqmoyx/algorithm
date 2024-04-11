#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges) {
        auto n = nums.size();
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        int d[mx + 1], id[mx + 1];
        memset(d, 0, sizeof d);
        memset(id, 0, sizeof id);

        int h[n], e[n << 1], ne[n << 1], idx = 0;
        memset(h, -1, sizeof h);
        auto add = [&](int a, int b) {
            e[idx] = b, ne[idx] = h[a], h[a] = idx++;
        };
        for (auto &edge: edges) {
            add(edge[0], edge[1]);
            add(edge[1], edge[0]);
        }
        vector<vector<int>> v(mx + 1);
        for (int i = mn; i <= mx; i++) {
            for (int j = i; j <= mx; j++) {
                if (gcd(i, j) == 1) {
                    v[i].emplace_back(j);
                    if (i != j) v[j].emplace_back(i);
                }
            }
        }
        vector<int> res(n, -1);
        function<void(int, int, int)> dfs = [&](int u, int p, int depth) {
            int max_depth = 0;
            for (int x: v[nums[u]]) {
                if (d[x] > max_depth) {
                    max_depth = d[x];
                    res[u] = id[x];
                }
            }
            int td = d[nums[u]], ti = id[nums[u]];
            d[nums[u]] = depth;
            id[nums[u]] = u;
            for (int i = h[u]; ~i; i = ne[i]) {
                int j = e[i];
                if (j != p) {
                    dfs(j, u, depth + 1);
                }
            }
            d[nums[u]] = td, id[nums[u]] = ti;
        };
        dfs(0, -1, 1);
        return res;
    }
};
