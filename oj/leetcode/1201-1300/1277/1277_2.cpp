#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>> &matrix) {
        auto n = matrix.size(), m = matrix[0].size();
        int res = 0;
        int f[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0) f[i][j] = matrix[i][j];
                else if (!matrix[i][j]) f[i][j] = 0;
                else f[i][j] = min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + 1;
                res += f[i][j];
            }
        }
        return res;
    }
};