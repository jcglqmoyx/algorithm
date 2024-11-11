#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        int f[n + 1][n + 1];
        for (int i = n - 1; i >= 0; i--) {
            f[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    f[i][j] = f[i][j - 1];
                } else {
                    int mn = INT32_MAX;
                    for (int k = i; k < j; k++) {
                        mn = min(mn, f[i][k] + f[k + 1][j]);
                    }
                    f[i][j] = mn;
                }
            }
        }
        return f[0][n - 1];
    }
};
