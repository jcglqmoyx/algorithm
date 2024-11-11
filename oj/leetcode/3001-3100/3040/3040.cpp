#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int> &v) {
        int n = v.size();
        int f[n][n];
        function<int(int)> dp = [&](int target) -> int {
            memset(f, 0, sizeof f);
            for (int len = 2; len <= n; len++) {
                for (int i = 0; i + len - 1 < n; i++) {
                    int j = i + len - 1;
                    if (len == 2) {
                        f[i][j] = v[i] + v[j] == target ? 1 : 0;
                    } else {
                        if (v[i] + v[i + 1] == target) f[i][j] = f[i + 2][j] + 1;
                        if (v[j] + v[j - 1] == target) f[i][j] = max(f[i][j], f[i][j - 2] + 1);
                        if (v[i] + v[j] == target) f[i][j] = max(f[i][j], f[i + 1][j - 1] + 1);
                    }
                }
            }
            return f[0][n - 1];
        };
        return max(dp(v[0] + v[1]), max(dp(v[n - 1] + v[n - 2]), dp(v[0] + v[n - 1])));
    }
};