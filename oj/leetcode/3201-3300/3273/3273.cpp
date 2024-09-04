#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minDamage(int power, vector<int> &damage, vector<int> &health) {
        using ll = long long;
        auto n = damage.size();
        int id[n];
        iota(id, id + n, 0);
        sort(id, id + n, [&](int a, int b) {
            return (health[a] + power - 1) / power * damage[b] < (health[b] + power - 1) / power * damage[a];
        });
        ll d = accumulate(damage.begin(), damage.end(), 0LL);
        ll res = 0;
        for (int i = 0; i < n; i++) {
            res += (health[id[i]] + power - 1) / power * d;
            d -= damage[id[i]];
        }
        return res;
    }
};