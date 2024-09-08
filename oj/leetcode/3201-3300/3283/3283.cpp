#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int N = 50;
    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    int get_dist(int a, int b, int x, int y) {
        queue<pair<int, int>> q;
        q.emplace(a, b);
        int step = 0;
        bool st[N][N];
        memset(st, 0, sizeof st);
        st[a][b] = true;

        while (!q.empty()) {
            step++;
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                int u = t.first, v = t.second;
                if (abs(u - x) + abs(v - y) <= 5) {
                    for (int i = 0; i < 8; i++) {
                        int nu = u + dx[i], nv = v + dy[i];
                        if (nu < 0 || nu >= N || nv < 0 || nv >= N || st[nu][nv]) continue;
                        if (nu == x && nv == y) {
                            return step;
                        }
                        q.emplace(nu, nv);
                        st[nu][nv] = true;
                    }
                } else {
                    for (int i = 0; i < 8; i++) {
                        int nu = u + dx[i], nv = v + dy[i];
                        if (nu < 0 || nu >= N || nv < 0 || nv >= N || st[nu][nv]) continue;
                        if (abs(nu - x) + abs(nv - y) < abs(u - x) + abs(v - y)) {
                            q.emplace(nu, nv);
                            st[nu][nv] = true;
                        }
                    }
                }
            }
        }
        return step;
    }

public:
    int maxMoves(int kx, int ky, vector<vector<int>> &positions) {
        int n = positions.size();
        int dist[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                dist[i][j] = dist[j][i] = get_dist(positions[i][0], positions[i][1], positions[j][0], positions[j][1]);
            }
        }
        int f[n][1 << n];
        memset(f, -1, sizeof f);
        function<int(int, int)> dp = [&](int i, int j) -> int {
            int cnt = __builtin_popcount(j);
            if (cnt == 0) return 0;
            if (f[i][j] != -1) return f[i][j];
            if ((cnt & 1) != (n & 1)) {
                f[i][j] = 1e8;
                for (int u = 0; u < n; u++) {
                    if (j >> u & 1) {
                        f[i][j] = min(f[i][j], dp(u, j ^ (1 << u)) + dist[i][u]);
                    }
                }
            } else {
                f[i][j] = 0;
                for (int u = 0; u < n; u++) {
                    if (j >> u & 1) {
                        f[i][j] = max(f[i][j], dp(u, j ^ (1 << u)) + dist[i][u]);
                    }
                }
            }
            return f[i][j];
        };
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, get_dist(kx, ky, positions[i][0], positions[i][1]) + dp(i, ((1 << n) - 1) ^ (1 << i)));
        }
        return res;
    }
};