#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory) {
        auto n = robot.size(), m = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        long long f[m + 1][n + 1];
        memset(f, 0x3f, sizeof f);
        for (int i = 0; i <= m; i++) {
            f[i][0] = 0;
        }
        for (int i = 1; i <= m; i++) {
            auto &fac = factory[i - 1];
            for (int j = 1; j <= n; j++) {
                long long move = 0;
                f[i][j] = f[i - 1][j];
                for (int k = 1; k <= min(j, fac[1]); k++) {
                    move += abs(fac[0] - robot[j - k]);
                    f[i][j] = min(f[i][j], f[i - 1][j - k] + move);
                }
            }
        }
        return f[m][n];
    }
};