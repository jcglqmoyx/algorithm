#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries) {
        int n = queries.size();
        bool st[numCourses][numCourses];
        bool vis[numCourses];
        memset(st, 0, sizeof st);
        for (auto &p: prerequisites) {
            st[p[0]][p[1]] = true;
        }
        auto dfs = [&](auto &&dfs, int init, int cur) -> void {
            if (init != cur) {
                st[init][cur] = true;
            }
            for (int i = 0; i < numCourses; i++) {
                if (st[cur][i] && !vis[i]) {
                    dfs(dfs, init, i);
                    vis[i] = true;
                }
            }
        };
        for (int i = 0; i < numCourses; i++) {
            memset(vis, 0, sizeof vis);
            vis[i] = true;
            dfs(dfs, i, i);
        }
        vector<bool> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = st[queries[i][0]][queries[i][1]];
        }
        return res;
    }
};