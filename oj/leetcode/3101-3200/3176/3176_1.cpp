#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int> &nums, int k) {
        int n = nums.size();
        int f[n][k + 1];
        memset(f, -0x3f, sizeof f);
        int res = 1;
        for (int i = 0; i < n; i++) {
            f[i][0] = 1;
            for (int j = 0; j <= k; j++) {
                for (int u = 0; u < i; u++) {
                    if (nums[i] == nums[u]) {
                        f[i][j] = max(f[i][j], f[u][j] + 1);
                    } else if (j) {
                        f[i][j] = max(f[i][j], f[u][j - 1] + 1);
                    }
                }
                res = max(res, f[i][j]);
            }
        }
        return res;
    }
};