#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        int f[n];
        memset(f, 0x3f, sizeof f);
        f[src] = 0;
        for (int i = 0; i < k + 1; i++) {
            int g[n];
            memcpy(g, f, sizeof f);
            for (auto &flight: flights) {
                int x = flight[0], y = flight[1], w = flight[2];
                f[y] = min(f[y], g[x] + w);
            }
        }
        return f[dst] == 0x3f3f3f3f ? -1 : f[dst];
    }
};