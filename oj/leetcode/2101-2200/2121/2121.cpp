#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> getDistances(vector<int> &arr) {
        using ll = long long;
        int n = arr.size();
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++) {
            map[arr[i]].emplace_back(i);
        }
        vector<ll> res(n);
        for (auto &[k, v]: map) {
            int m = v.size();
            ll l = 0, r = 0;
            for (int p: v) r += p;
            for (int i = 0; i < m; i++) {
                l += v[i];
                r -= v[i];
                res[v[i]] = ((i + 1LL) * v[i] - l) + (r - (v[i] * (m - i - 1LL)));
            }
        }
        return res;
    }
};