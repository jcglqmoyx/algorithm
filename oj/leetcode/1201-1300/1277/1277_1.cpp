#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>> &matrix) {
        auto n = matrix.size(), m = matrix[0].size();
        int s[n + 1][m + 1];
        memset(s, 0, sizeof s);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        auto check = [&](int x, int y, int len) {
            return s[x][y] - s[x - len][y] - s[x][y - len] + s[x - len][y - len] == len * len;
        };
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int l = 0, r = min(i, j);
                while (l < r) {
                    int mid = (l + r + 1) >> 1;
                    if (check(i, j, mid)) l = mid;
                    else r = mid - 1;
                }
                res += l;
            }
        }
        return res;
    }
};