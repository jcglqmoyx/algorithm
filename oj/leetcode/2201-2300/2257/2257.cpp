#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls) {
        const int G = -2, W = -1;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int st[m][n];
        memset(st, 0, sizeof st);
        for (auto &g: guards) {
            st[g[0]][g[1]] = G;
        }
        for (auto &w: walls) {
            st[w[0]][w[1]] = W;
        }
        for (auto &g: guards) {
            int r = g[0], c = g[1];
            for (int i = 0; i < 4; i++) {
                int x = r, y = c;
                while (true) {
                    x += dx[i], y += dy[i];
                    if (x < 0 || x == m || y < 0 || y == n || st[x][y] == G || st[x][y] == W || st[x][y] >> i & 1) {
                        break;
                    }
                    st[x][y] |= 1 << i;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!st[i][j]) {
                    res++;
                }
            }
        }
        return res;
    }
};