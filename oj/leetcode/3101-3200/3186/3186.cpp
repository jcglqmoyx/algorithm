#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int> &power) {
        using ll = long long;
        unordered_map<int, int> mp;
        for (int x: power) mp[x]++;
        sort(power.begin(), power.end());
        power.erase(unique(power.begin(), power.end()), power.end());
        int n = power.size();
        ll f[n];
        memset(f, 0, sizeof f);
        f[0] = power[0] * 1LL * mp[power[0]];
        for (int i = 1; i < n; i++) {
            int x = power[i], c = mp[x];
            f[i] = x * 1LL * c;
            for (int j = i - 1; j >= 0; j--) {
                f[i] = max(f[i], f[j]);
                if (power[j] < power[i] - 2) {
                    f[i] = max(f[i], f[j] + x * 1LL * c);
                    break;
                }
            }
        }
        return f[n - 1];
    }
};