#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        int m = primes.size();
        long long f[n + 1];
        int p[m];
        f[1] = 1;
        fill(p, p + m, 1);
        for (int i = 2; i <= n; i++) {
            long long mn = INT64_MAX;
            for (int j = 0; j < m; j++) {
                mn = min(mn, f[p[j]] * primes[j]);
            }
            f[i] = mn;
            for (int j = 0; j < m; j++) {
                if (mn == f[p[j]] * primes[j]) {
                    p[j]++;
                }
            }
        }
        return f[n];
    }
};