#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>> &board) {
        int initial = 0, final = 0;
        for (int k = 0, i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++, k++) {
                initial |= board[i][j] * (1 << k * 5);
                final |= (k == 5 ? 0 : k + 1) << (k * 5);
            }
        }
        if (initial == final) {
            return 0;
        }
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        unordered_set<int> vis = {initial};
        queue<int> q;
        q.emplace(initial);
        int step = 0;
        while (!q.empty()) {
            step++;
            for (auto _ = q.size(); _; _--) {
                int t = q.front();
                q.pop();
                int g[2][3];
                int x = -1, y = -1;
                for (int k = 0, i = 0; i < 2; i++) {
                    for (int j = 0; j < 3; j++, k++) {
                        g[i][j] = t >> (k * 5) & 31;
                        if (g[i][j] == 0) {
                            x = i, y = j;
                        }
                    }
                }
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx >= 0 && nx < 2 && ny >= 0 && ny < 3) {
                        swap(g[x][y], g[nx][ny]);
                        int st = 0;
                        for (int k = 0, i = 0; i < 2; i++) {
                            for (int j = 0; j < 3; j++, k++) {
                                st |= g[i][j] * (1 << k * 5);
                            }
                        }
                        if (st == final) {
                            return step;
                        }
                        if (!vis.contains(st)) {
                            q.emplace(st);
                            vis.emplace(st);
                        }
                        swap(g[x][y], g[nx][ny]);
                    }
                }
            }
        }
        return -1;
    }
};