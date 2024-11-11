#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory) {
        auto n = robot.size(), m = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        long long f[n + 1];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 0; i < m; i++) {
            auto &fac = factory[i];
            long long g[n + 1];
            memset(g, 0x3f, sizeof g);
            g[0] = 0;
            for (int j = 1; j <= n; j++) {
                long long move = 0;
                g[j] = f[j];
                for (int k = 1; k <= min(j, fac[1]); k++) {
                    move += abs(fac[0] - robot[j - k]);
                    g[j] = min(g[j], f[j - k] + move);
                }
            }
            memcpy(f, g, sizeof g);
        }
        return f[n];
    }
};