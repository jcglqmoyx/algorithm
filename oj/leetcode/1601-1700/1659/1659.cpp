#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        if (m < n) swap(m, n);
        int tot = 1, inf = 100000;
        for (int i = 0; i < n; i++) tot *= 3;

        int f[m][introvertsCount + 1][extrovertsCount + 1][tot];
        memset(f, -0x3f, sizeof f);

        int table1[3][3] = {
                {0,   0,  0},
                {120, 60, 110},
                {40,  30, 80},
        };

        int table2[3][3] = {
                {0, 0,   0},
                {0, -60, -10},
                {0, -10, 40},
        };

        // 0: no one, 1: introvert,  2: extrovert
        int row_happiness[tot];
        memset(row_happiness, 0, sizeof row_happiness);
        int in[tot], ex[tot];
        memset(in, 0, sizeof in);
        memset(ex, 0, sizeof ex);
        for (int i = 0; i < tot; i++) {
            int mask = i;
            for (int prev = 0, j = 0; j < n; j++) {
                int type = mask % 3;
                if (type == 1) in[i]++;
                else if (type == 2) ex[i]++;
                row_happiness[i] += table1[type][prev];
                prev = type;
                mask /= 3;
            }
            if (in[i] > introvertsCount || ex[i] > extrovertsCount) row_happiness[i] = -inf;
            else f[0][in[i]][ex[i]][i] = row_happiness[i];
        }

        int inter_row_happiness[tot][tot];
        for (int i = 0; i < tot; i++) {
            for (int last = 0; last < tot; last++) {
                if (row_happiness[i] == -inf || row_happiness[last] == -inf) inter_row_happiness[i][last] = -inf;
                else {
                    inter_row_happiness[i][last] = row_happiness[i];
                    if (last) {
                        int a = i, b = last;
                        for (int j = 0; j < n; j++) {
                            int x = a % 3, y = b % 3;
                            inter_row_happiness[i][last] += table2[x][y];
                            a /= 3, b /= 3;
                        }
                    }
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int a = 0; a <= min(introvertsCount, (i + 1) * n); a++) {
                for (int b = 0; b <= min(extrovertsCount, (i + 1) * n - a); b++) {
                    for (int cur = 0; cur < tot; cur++) {
                        if (a < in[cur] || b < ex[cur]) continue;
                        int &t = f[i][a][b][cur];
                        for (int last = 0; last < tot; last++) {
                            t = max(t, f[i - 1][a - in[cur]][b - ex[cur]][last] + inter_row_happiness[cur][last]);
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int i = 1; i < tot; i++) {
            for (int a = 0; a <= min(introvertsCount, m * n); a++) {
                for (int b = 0; b <= min(extrovertsCount, m * n - a); b++) {
                    res = max(res, f[m - 1][a][b][i]);
                }
            }
        }
        return res;
    }
};