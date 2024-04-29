#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        for (int id = 0; id < n + m - 1; id++) {
            vector<int> v;
            int r = 0, c = m - 1 - id;
            if (id >= m) {
                r = id - m + 1;
                c = 0;
            }
            for (int i = r, j = c; i < n && j < m; i++, j++) {
                v.emplace_back(mat[i][j]);
            }
            sort(v.begin(), v.end());
            for (int i = r, j = c, u = 0; i < n && j < m; i++, j++, u++) {
                mat[i][j] = v[u];
            }
        }
        return mat;
    }
};