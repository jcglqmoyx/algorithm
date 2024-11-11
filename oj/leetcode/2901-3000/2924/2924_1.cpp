#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>> &edges) {
        vector<bool> vis(n);
        vector<int> d(n, 0);
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            d[e[1]]++;
            g[e[0]].emplace_back(e[1]);
        }
        function<void(int)> dfs = [&](int u) {
            vis[u] = true;
            for (int x: g[u]) {
                if (!vis[x]) {
                    dfs(x);
                }
            }
        };
        for (int i = 0; i < n; i++) {
            if (d[i] == 0) {
                dfs(i);
                for (int j = 0; j < n; j++) {
                    if (!vis[j]) {
                        return -1;
                    }
                }
                return i;
            }
        }
        return -1;
    }
};