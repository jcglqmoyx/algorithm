#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size(), f[n + 1];
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = i;
            int c1[26]{}, c2[n + 1], t = 0;
            memset(c2, 0, sizeof c2);
            for (int j = i; j >= 1; j--) {
                int u = s[j - 1] - 'a';
                c1[u]++;
                c2[c1[u]]++;
                c2[c1[u] - 1]--;
                if (c2[c1[u]] == 1) t++;
                if (c2[c1[u] - 1] == 0) t--;

                if (t == 1) f[i] = min(f[i], f[j - 1] + 1);
            }
        }
        return f[n];
    }
};