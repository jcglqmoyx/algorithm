#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int> &targetIndices) {
        int n = static_cast<int>(source.size()), m = static_cast<int>(pattern.size());
        bool st[n + 1];
        memset(st, 0, sizeof st);
        for (int x: targetIndices) {
            st[x + 1] = true;
        }
        int f[m + 1];
        memset(f, -0x3f, sizeof f);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = min(i, m); j >= 1; j--) {
                f[j] += st[i];
                if (source[i - 1] == pattern[j - 1]) {
                    f[j] = max(f[j], f[j - 1]);
                }
            }
            f[0] += st[i];
        }
        return f[m];
    }
};