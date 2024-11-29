#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
        int m = static_cast<int> (richer.size()) + 1, n = static_cast<int>(quiet.size());
        int h[n], e[m], ne[m], idx = 0;
        int d[n];
        memset(h, -1, sizeof h);
        memset(d, 0, sizeof d);
        for (auto &r: richer) {
            e[idx] = r[1], ne[idx] = h[r[0]], h[r[0]] = idx++;
            d[r[1]]++;
        }
        vector<int> res(n);
        int q[n];
        int hh = 0, tt = -1;
        for (int i = 0; i < n; i++) {
            res[i] = i;
            if (!d[i]) {
                q[++tt] = i;
            }
        }
        while (hh <= tt) {
            int t = q[hh++];
            for (int i = h[t]; ~i; i = ne[i]) {
                int j = e[i];
                if (quiet[t] <= quiet[j]) {
                    quiet[j] = quiet[t];
                    res[j] = res[t];
                }
                if (--d[j] == 0) {
                    q[++tt] = j;
                }
            }
        }
        return res;
    }
};