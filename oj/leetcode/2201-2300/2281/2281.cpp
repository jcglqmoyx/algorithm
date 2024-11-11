#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalStrength(vector<int> &strength) {
        using ll = long long;
        int n = strength.size(), m = 1e9 + 7;
        int s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = (s[i - 1] + strength[i - 1]) % m;
        }
        ll ss[n + 2];
        ss[0] = ss[1] = 0;
        for (int i = 2; i <= n + 1; i++) {
            ss[i] = (ss[i - 1] + s[i - 1]) % m;
        }
        int stk[n], l[n + 1];
        for (int tt = -1, i = 1; i <= n; i++) {
            while (~tt && strength[stk[tt] - 1] >= strength[i - 1]) tt--;
            l[i] = ~tt ? stk[tt] + 1 : 1;
            stk[++tt] = i;
        }
        ll res = 0;
        for (int tt = -1, i = n; i; i--) {
            while (~tt && strength[stk[tt] - 1] > strength[i - 1]) tt--;
            int ri = ~tt ? stk[tt] - 1 : n;
            ll t = (((ss[ri + 1] - ss[i]) * (i - l[i] + 1LL) - (ss[i] - ss[l[i] - 1]) * (ri - i + 1LL)) % m + m) % m;
            res = (res + strength[i - 1] * t % m) % m;
            stk[++tt] = i;
        }
        return res;
    }
};