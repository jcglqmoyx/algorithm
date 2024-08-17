#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>> &points) {
        int n = points.size(), m = points[0].size();
        long long f[m];
        for (int j = 0; j < m; j++) {
            f[j] = points[0][j];
        }
        for (int i = 1; i < n; i++) {
            long long l[m], r[m];
            for (int j = 0; j < m; j++) {
                l[j] = f[j] + j;
                r[j] = f[j] - j;
            }
            long long mx = INT64_MIN;
            for (int j = 0; j < m; j++) {
                mx = max(mx, l[j]);
                f[j] = mx - j;
            }
            mx = INT64_MIN;
            for (int j = m - 1; j >= 0; j--) {
                mx = max(mx, r[j]);
                f[j] = max(f[j], mx + j) + points[i][j];
            }
        }
        return *max_element(f, f + m);
    }
};