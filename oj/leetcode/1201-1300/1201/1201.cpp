#include <bits/stdc++.h>

using namespace std;

class Solution {
    long long lca_ab, lca_ac, lca_bc, lca_abc;
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        auto check = [&](auto m) {
            return m / a + m / b + m / c - m / (lca_ab) - m / (lca_ac) - m / (lca_bc) + m / (lca_abc) >= n;
        };
        long long l = 1, r = min(n * 1LL * c, 2000000000LL);
        lca_ab = a * 1LL * b / gcd(a, b);
        lca_ac = a * 1LL * c / gcd(a, c);
        lca_bc = b * 1LL * c / gcd(b, c);
        lca_abc = lca_ab * 1LL * c / gcd(lca_ab, c);
        while (l < r) {
            auto m = (l + r) >> 1;
            if (check(m)) r = m;
            else l = m + 1;
        }
        return (int) l;
    }
};