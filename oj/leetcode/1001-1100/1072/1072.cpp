#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
        auto n = matrix.size(), m = matrix[0].size();
        int res = 0;
        map<vector<int>, int> cnt;
        for (int i = 0; i < n; i++) {
            cnt[matrix[i]]++;
            vector<int> t(m);
            for (int j = 0; j < m; j++) {
                t[j] = matrix[i][j] ^ 1;
            }
            res = max(res, cnt[matrix[i]] + cnt[t]);
        }
        return res;
    }
};