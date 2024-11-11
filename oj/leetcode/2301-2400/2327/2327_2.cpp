#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int f[n + 1], m = 1e9 + 7;
        memset(f, 0, sizeof f);
        f[1] = 1;
        for (int i = 2; i <= n; i++) {
            int t = 0;
            if (i >= delay) {
                t = f[i - delay];
                if (i - forget >= 0) {
                    t = (t - f[i - forget] + m) % m;
                }
            }
            f[i] = (t + f[i - 1]) % m;
        }
        return (f[n] - f[n - forget] + m) % m;
    }
};