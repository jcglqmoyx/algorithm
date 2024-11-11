#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>> &grid) {
        int n = (int) grid.size();
        if (n == 1) return 0;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        auto check = [&](int mid) {
            bool st[n][n];
            memset(st, 0, sizeof st);
            st[0][0] = true;
            queue<pair<int, int>> q;
            q.emplace(0, 0);
            while (!q.empty()) {
                auto t = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int a = t.first + dx[i], b = t.second + dy[i];
                    if (a >= 0 && a < n && b >= 0 && b < n && !st[a][b] && grid[t.first][t.second] <= mid &&
                        grid[a][b] <= mid) {
                        if (a == n - 1 && b == n - 1) return true;
                        q.emplace(a, b);
                        st[a][b] = true;
                    }
                }
            }
            return false;
        };
        int l = 0, r = n * n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};