#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int f[n], m = 1e9 + 7;
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int i = delay; i < n; i++) {
            for (int j = i - delay; j > i - forget && j >= 0; j--) {
                f[i] = (f[i] + f[j]) % m;
            }
        }
        int res = 0;
        for (int i = n - 1; i > n - 1 - forget && i >= 0; i--) {
            res = (res + f[i]) % m;
        }
        return res;
    }
};