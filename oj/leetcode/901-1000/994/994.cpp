#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        auto n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.emplace(i, j);
                }
            }
        }
        if (!fresh) return 0;
        int step = 0;
        while (!q.empty()) {
            step++;
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int x = t.first + dx[i], y = t.second + dy[i];
                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                        fresh--;
                        if (!fresh) return step;
                        q.emplace(x, y);
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return -1;
    }
};