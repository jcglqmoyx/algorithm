#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors) {
        auto n = students.size(), m = students[0].size();
        int f[1 << n], c[n][n];
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = 0;
                for (int k = 0; k < m; k++) {
                    c[i][j] += students[i][k] == mentors[j][k];
                }
            }
        }
        for (int i = 1; i < 1 << n; i++) {
            int cnt = __builtin_popcount(i);
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    f[i] = max(f[i], f[i ^ (1 << j)] + c[cnt - 1][j]);
                }
            }
        }
        return f[(1 << n) - 1];
    }
};