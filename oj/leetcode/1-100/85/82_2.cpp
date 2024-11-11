#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int fl[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!j || matrix[i][j] == '0') fl[i][j] = matrix[i][j] & 1;
                else fl[i][j] = fl[i][j - 1] + 1;
            }
        }
        int res = 0;
        for (int j = 0; j < m; j++) {
            int up[n];
            int q[n], tt = -1;
            for (int i = 0; i < n; i++) {
                while (tt >= 0 && fl[i][j] <= fl[q[tt]][j]) tt--;
                up[i] = tt == -1 ? 0 : q[tt] + 1;
                q[++tt] = i;
            }
            tt = -1;
            for (int i = n - 1; i >= 0; i--) {
                while (tt >= 0 && fl[i][j] <= fl[q[tt]][j]) tt--;
                res = max(res, fl[i][j] * ((tt == -1 ? n - 1 : q[tt] - 1) - up[i] + 1));
                q[++tt] = i;
            }
        }
        return res;
    }
};