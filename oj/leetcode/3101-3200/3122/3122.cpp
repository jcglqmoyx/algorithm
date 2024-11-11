#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int f1 = 0, f2 = 0, pre;
        for (int j = 0; j < m; j++) {
            int mx1 = -1, mx2 = -1, v = -1;
            int cnt[10]{};
            for (int i = 0; i < n; i++) {
                cnt[grid[i][j]]++;
            }
            for (int u = 0; u <= 9; u++) {
                int res = (u == pre ? f2 : f1) + cnt[u];
                if (res > mx1) {
                    mx2 = mx1;
                    mx1 = res;
                    v = u;
                } else if (res > mx2) {
                    mx2 = res;
                }
            }
            f1 = mx1;
            f2 = mx2;
            pre = v;
        }
        return n * m - f1;
    }
};