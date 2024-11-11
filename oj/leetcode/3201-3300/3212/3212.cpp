#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int s[n + 1][m + 1], t[n + 1][m + 1];
        memset(s, 0, sizeof s);
        memset(t, 0, sizeof t);
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (grid[i - 1][j - 1] == 'X');
                t[i][j] = t[i - 1][j] + t[i][j - 1] - t[i - 1][j - 1] + (grid[i - 1][j - 1] == 'Y');
                if (s[i][j] && s[i][j] == t[i][j]) {
                    res++;
                }
            }
        }
        return res;
    }
};