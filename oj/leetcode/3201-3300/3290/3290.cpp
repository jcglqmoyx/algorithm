#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxScore(vector<int> &a, vector<int> &b) {
        using ll = long long;
        auto n = b.size();
        ll mn = INT64_MIN / 2, res = mn;
        ll f[5] = {0, mn, mn, mn, mn};
        for (int i = 0; i < n; i++) {
            for (int j = 4; j; j--) {
                f[j] = max(f[j], f[j - 1] + (ll) b[i] * a[j - 1]);
            }
            res = max(res, f[4]);
        }
        return res;
    }
};