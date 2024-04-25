#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        int f[26]{};
        for (char c: s) {
            int g[26];
            memcpy(g, f, sizeof f);
            int u = c - 'a';
            for (int i = max(u - k, 0); i <= min(u + k, 25); i++) {
                g[u] = max(g[u], f[i] + 1);
            }
            memcpy(f, g, sizeof g);
        }
        return *max_element(f, f + 26);
    }
};