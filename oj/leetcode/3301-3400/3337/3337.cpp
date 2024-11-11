#include <bits/stdc++.h>

using namespace std;

using LL = long long;

static constexpr int MOD = 1'000'000'007;

vector<vector<LL>> multiply(vector<vector<LL>> a, vector<vector<LL>> b) {
    auto rows = a.size(), columns = b[0].size(), temp = b.size();
    vector<vector<LL>> c(rows, vector<LL>(columns));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            for (int k = 0; k < temp; k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}

vector<vector<LL>> pow(vector<vector<LL>> mat, int n) {
    vector<vector<LL>> ret = mat;
    n--;
    while (n > 0) {
        if ((n & 1) == 1) {
            ret = multiply(ret, mat);
        }
        n >>= 1;
        mat = multiply(mat, mat);
    }
    return ret;
}

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int> &nums) {
        vector<vector<LL>> cnt(26, vector<LL>(1));
        for (char c: s) {
            cnt[c - 'a'][0]++;
        }

        vector<vector<LL>> mat(26, vector<LL>(26));
        for (int i = 0; i < 26; i++) {
            for (int x = i + 1; x <= i + nums[i]; x++) {
                mat[x % 26][i] = 1;
            }
        }
        auto matrix = multiply(pow(mat, t), cnt);

        int res = 0;
        for (int i = 0; i < 26; i++) {
            res = (res + matrix[i][0]) % MOD;
        }
        return res;
    }
};