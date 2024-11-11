#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int MOD = 1e9 + 7;

vector<vector<LL>> multiply(vector<vector<LL>> a, vector<vector<LL>> &b) {
    auto n = a.size(), m = b[0].size(), k = b.size();
    vector<vector<LL>> res(n, vector<LL>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int u = 0; u < k; u++) {
                res[i][j] = (res[i][j] + a[i][u] * b[u][j]) % MOD;
            }
        }
    }
    return res;
}

vector<vector<LL>> pow(vector<vector<LL>> mat, int n) {
    auto res = mat;
    n--;
    while (n) {
        if (n & 1) res = multiply(res, mat);
        mat = multiply(mat, mat);
        n >>= 1;
    }
    return res;
}

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<vector<LL>> mat(26, vector<LL>(26));
        vector<vector<LL>> cnt(26, vector<LL>(1));
        for (char c: s) {
            cnt[c - 'a'][0]++;
        }
        for (int i = 0; i < 26; i++) {
            mat[i][(i - 1 + 26) % 26] = 1;
        }
        mat[1][25] = 1;
        auto matrix = multiply(pow(mat, t), cnt);
        int res = 0;
        for (int i = 0; i < 26; i++) {
            res = (res + matrix[i][0]) % MOD;
        }
        return res;
    }
};