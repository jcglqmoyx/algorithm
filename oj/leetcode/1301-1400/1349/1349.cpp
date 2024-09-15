#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxStudents(vector<vector<char>> &seats) {
        auto n = seats.size(), m = seats[0].size();
        int f[1 << m];
        memset(f, 0, sizeof f);
        int cnt[1 << m];
        memset(cnt, 0, sizeof cnt);
        for (int mask = 1; mask < 1 << m; mask++) {
            if ((mask & -mask) == mask) cnt[mask] = 1;
            else cnt[mask] = cnt[mask ^ (mask & -mask)] + 1;
            bool flag = true;
            for (int j = 0; j < m; j++) {
                if (seats[0][j] == '#' && mask >> j & 1) {
                    flag = false;
                    break;
                }
                if (j && mask >> j & 1 && mask >> (j - 1) & 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                f[mask] = cnt[mask];
            }
        }
        for (int i = 1; i < n; i++) {
            int g[1 << m];
            memset(g, 0, sizeof g);
            for (int cur = 0; cur < 1 << m; cur++) {
                bool flag = true;
                int v[m], idx = 0;
                int mask = (1 << m) - 1;
                for (int j = 0; j < m; j++) {
                    if (cur >> j & 1) {
                        v[idx++] = j;
                        if (seats[i][j] == '#' || j && cur >> (j - 1) & 1) {
                            flag = false;
                            break;
                        }
                        if (j && mask >> (j - 1) & 1) mask ^= 1 << (j - 1);
                        if (j + 1 < m && mask >> (j + 1) & 1) mask ^= 1 << (j + 1);
                    }
                }
                if (flag) {
                    for (int last = mask; last; last = (last - 1) & mask) {
                        g[cur] = max(g[cur], f[last] + cnt[cur]);
                    }
                    g[cur] = max(g[cur], f[0] + cnt[cur]);
                }
            }
            memcpy(f, g, sizeof g);
        }
        int res = 0;
        for (int i = 0; i < 1 << m; i++) {
            res = max(res, f[i]);
        }
        return res;
    }
};