#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>> &moveTime) {
        int n = static_cast<int>(moveTime.size()), m = static_cast<int>(moveTime[0].size());
        int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        int f[n][m];
        memset(f, 0x3f, sizeof f);
        f[0][0] = 0;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a == n || b < 0 || b == m || f[a][b] <= f[x][y] + 1) continue;
                f[a][b] = max(f[x][y], moveTime[a][b]) + 1;
                q.emplace(a, b);
            }
        }
        return f[n - 1][m - 1];
    }
};