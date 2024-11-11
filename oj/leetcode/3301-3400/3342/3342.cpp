#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>> &moveTime) {
        int n = static_cast<int>(moveTime.size()), m = static_cast<int>(moveTime[0].size());
        int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        int f[n][m];
        memset(f, 0x3f, sizeof f);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        q.emplace(0, 0, 0);
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            auto [dist, x, y] = t;
            if (x == n - 1 && y == m - 1) {
                return dist;
            }
            if (f[x][y] <= dist) {
                continue;
            }
            f[x][y] = dist;
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                int dt = ((x + y) & 1) + 1;
                if (a < 0 || a == n || b < 0 || b == m || f[a][b] <= f[x][y] + dt) {
                    continue;
                }
                int d = max(dist, moveTime[a][b]) + dt;
                q.emplace(d, a, b);
            }
        }
        return f[n - 1][m - 1];
    }
};