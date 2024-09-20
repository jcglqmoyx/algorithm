#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        using LL = long long;
        const LL BASE = 131, MOD = 1e9 + 7;
        auto n = s.size();
        int len = 0;
        LL l = 0, r = 0, mul = 1;
        for (int i = 0; i < n; i++) {
            l = (l * BASE + s[i]) % MOD;
            r = (s[i] * mul + r) % MOD;
            mul = mul * BASE % MOD;
            if (l == r) len = i + 1;
        }
        auto t = s.substr(len);
        reverse(t.begin(), t.end());
        return t + s;
    }
};