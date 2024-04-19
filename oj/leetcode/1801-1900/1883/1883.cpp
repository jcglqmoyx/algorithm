#include <bits/stdc++.h>

using namespace std;

/*
class Solution {
public:
    int minSkips(vector<int> &dist, int speed, int hoursBefore) {
        const double eps = 1e-8;
        long long tot = accumulate(dist.begin(), dist.end(), 0LL);
        if (tot > hoursBefore * 1LL * speed) return -1;

        size_t n = dist.size();
        double f[n + 1][n + 1];
        memset(f, 0x7f, sizeof f);
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            double d = dist[i - 1], t = d / speed;
            f[i][0] = f[i - 1][0] + ceil(t - eps);
            for (int j = 1; j <= i; j++) {
                f[i][j] = min(f[i - 1][j - 1] + t, ceil(f[i - 1][j] + t - eps));
            }
        }
        for (int i = 0; i <= n; i++) {
            if (f[n][i] - eps < hoursBefore) {
                return i;
            }
        }
        return -1;
    }
};
 */

class Solution {
public:
    int minSkips(vector<int> &dist, int speed, int hoursBefore) {
        const double eps = 1e-8;
        long long tot = accumulate(dist.begin(), dist.end(), 0LL);
        if (tot > hoursBefore * 1LL * speed) return -1;

        size_t n = dist.size();
        double f[n + 1];
        memset(f, 0x7f, sizeof f);
        f[0] = 0;

        for (int i = 1; i <= n; i++) {
            double d = dist[i - 1], t = d / speed;
            for (int j = i; j >= 1; j--) {
                f[j] = min(f[j - 1] + t, ceil(f[j] + t - eps));
            }
            f[0] += ceil(t - eps);
        }
        for (int i = 0; i <= n; i++) {
            if (f[i] - eps < hoursBefore) {
                return i;
            }
        }
        return -1;
    }
};
