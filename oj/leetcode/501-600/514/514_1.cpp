#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        vector<vector<int>> p(26);
        int f[n];
        memset(f, 0x3f, sizeof f);
        for (int i = 0; i < n; i++) {
            p[ring[i] - 'a'].emplace_back(i);
            if (ring[i] == key[0]) {
                f[i] = min(i, n - i) + 1;
            }
        }
        for (int i = 1; i < key.size(); i++) {
            int g[n];
            memset(g, 0x3f, sizeof g);
            for (int j: p[key[i - 1] - 'a']) {
                for (int k: p[key[i] - 'a']) {
                    g[k] = min(g[k], f[j] + min(abs(k - j), n - abs(k - j)) + 1);
                }
            }
            memcpy(f, g, sizeof g);
        }
        int res = 1e8;
        for (int i: p[key.back() - 'a']) {
            res = min(res, f[i]);
        }
        return res;
    }
};