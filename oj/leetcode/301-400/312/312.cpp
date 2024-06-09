#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size(), res = 0;
        vector<int> v(n + 2);
        v[0] = v[n + 1] = 1;
        for (int i = 1; i <= n; i++) v[i] = nums[i - 1];
        int f[n + 2][n + 2];
        memset(f, 0, sizeof f);
        for (int len = 3; len <= n + 2; len++) {
            for (int i = 0; i + len - 1 < n + 2; i++) {
                int j = i + len - 1;
                for (int k = i + 1; k < j; k++) {
                    f[i][j] = max(f[i][j], v[i] * v[k] * v[j] + f[i][k] + f[k][j]);
                }
            }
        }
        return f[0][n + 1];
    }
};