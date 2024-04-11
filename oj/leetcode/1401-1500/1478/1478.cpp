#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(vector<int> &houses, int k) {
        size_t n = houses.size();
        sort(houses.begin(), houses.end());
        int s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + houses[i - 1];
        }
        int f[n + 1][k + 1];
        memset(f, 0x3f, sizeof f);
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                f[i][j] = f[i][j - 1];
                for (int u = 1; u <= i; u++) {
                    int mid = (u + i) / 2;
                    int l = houses[mid - 1] * (mid - u + 1) - (s[mid] - s[u - 1]);
                    int r = s[i] - s[mid] - houses[mid - 1] * (i - mid);
                    f[i][j] = min(f[i][j], f[u - 1][j - 1] + l + r);
                }
            }
        }
        return f[n][k];
    }
};