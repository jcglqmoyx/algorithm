#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minStickers(vector<string> &stickers, string target) {
        auto n = stickers.size(), m = target.size();
        int cs[n][26];
        memset(cs, 0, sizeof cs);
        for (int i = 0; i < n; i++) {
            for (char c: stickers[i]) {
                cs[i][c - 'a']++;
            }
        }
        int f[1 << m], inf = 0x3f3f3f3f;
        memset(f, -1, sizeof f);
        function<int(int)> dp = [&](int mask) -> int {
            if (!mask) return 0;
            if (f[mask] != -1) return f[mask];
            f[mask] = inf;
            for (int i = 0; i < n; i++) {
                int new_mask = mask;
                int dt[26]{};
                for (int j = 0; j < m; j++) {
                    if (mask >> j & 1) {
                        int u = target[j] - 'a';
                        if (dt[u] < cs[i][u]) {
                            dt[u]++;
                            new_mask ^= 1 << j;
                        }
                    }
                }
                if (new_mask != mask) {
                    f[mask] = min(f[mask], dp(new_mask) + 1);
                }
            }
            return f[mask];
        };
        int res = dp((1 << m) - 1);
        if (res >= inf) res = -1;
        return res;
    }
};