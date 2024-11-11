#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        auto n = matrix.size(), m = matrix[0].size();
        int fl[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!j || matrix[i][j] == '0') fl[i][j] = matrix[i][j] - '0';
                else fl[i][j] = fl[i][j - 1] + 1;
            }
        }
        int res = 0;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int mn = fl[i][j];
                for (int u = i; u >= 0; u--) {
                    mn = min(mn, fl[u][j]);
                    if (mn == 0) break;
                    res = max(res, mn * (i - u + 1));
                }
            }
        }
        return res;
    }
};