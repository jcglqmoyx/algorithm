#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int f[n + 1];
        memset(f, 0x3f, sizeof f);
        f[1] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i - 1; j++) {
                if (i % j == 0) {
                    f[i] = min(f[i], f[j] + i / j);
                }
            }
        }
        return f[n];
    }
};