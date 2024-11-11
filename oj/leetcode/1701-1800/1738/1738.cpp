#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>> &matrix, int k) {
        auto n = matrix.size(), m = matrix[0].size();
        int s[n + 1][m + 1], res = 0;
        memset(s, 0, sizeof s);
        int v[n * m];
        for (int idx = 0, i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                s[i][j] = s[i - 1][j] ^ s[i][j - 1] ^ matrix[i - 1][j - 1] ^ s[i - 1][j - 1];
                v[idx++] = s[i][j];
            }
        }
        nth_element(v, v + k - 1, v + n * m, greater<>());
        return v[k - 1];
    }
};