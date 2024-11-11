#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int twoEggDrop(int n) {
        int f[n + 1];
        for (int i = 0; i <= n; i++) {
            f[i] = i;
            for (int j = 1; j <= i; j++) {
                f[i] = min(f[i], max(j - 1, f[i - j]) + 1);
            }
        }
        return f[n];
    }
};
