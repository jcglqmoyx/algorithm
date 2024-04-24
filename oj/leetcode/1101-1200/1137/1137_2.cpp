#include <bits/stdc++.h>

using namespace std;

using LL = long long;

vector<vector<LL>> times(vector<vector<LL>> &a, vector<vector<LL>> &b) {
    int n1 = (int) a.size(), m1 = (int) a[0].size(), m2 = (int) b[0].size();
    vector<vector<LL>> res(n1, vector<LL>(m2));
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            for (int u = 0; u < m1; u++) {
                res[i][j] += a[i][u] * b[u][j];
            }
        }
    }
    return res;
}

vector<vector<LL>> quick_power(vector<vector<LL>> v, int n) {
    vector<vector<LL>> res = v;
    n--;
    while (n) {
        if (n & 1) {
            res = times(res, v);
        }
        v = times(v, v);
        n >>= 1;
    }
    return res;
}

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;
        vector<vector<LL>> matrix = {{1, 1, 0},
                                     {1, 0, 1},
                                     {1, 0, 0}};
        return (int) quick_power(matrix, n - 1)[0][0];
    }
};