#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        using LL = long long;
        const LL BASE1 = 131, MOD1 = 1e9 + 7;
        const LL BASE2 = 13331, MOD2 = 1e9 + 9;
        auto n = s.size();
        int len = 0;
        pair<int, int> l, r;
        LL mul1 = 1, mul2 = 1;
        for (int i = 0; i < n; i++) {
            l = {(l.first * BASE1 + s[i]) % MOD1, (l.second * BASE2 + s[i]) % MOD2};
            r = {(s[i] * mul1 + r.first) % MOD1, (s[i] * mul2 + r.second) % MOD2};
            mul1 = mul1 * BASE1 % MOD1;
            mul2 = mul2 * BASE2 % MOD2;
            if (l == r) len = i + 1;
        }
        auto t = s.substr(len);
        reverse(t.begin(), t.end());
        return t + s;
    }
};