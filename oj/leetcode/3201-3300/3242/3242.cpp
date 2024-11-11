#include <bits/stdc++.h>

using namespace std;

class NeighborSum {
    int dx1[4] = {1, 0, -1, 0}, dy1[4] = {0, 1, 0, -1};
    int dx2[4] = {1, -1, -1, 1}, dy2[4] = {1, 1, -1, -1};

    int n, m;
    vector<pair<int, int>> p;
    vector<vector<int>> g;
public:
    NeighborSum(vector<vector<int>> &grid) {
        g = std::move(grid);
        n = static_cast<int>(g.size());
        m = static_cast<int>(g[0].size());
        p.resize(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p[g[i][j]] = {i, j};
            }
        }
    }

    int adjacentSum(int value) {
        int s = 0;
        for (int i = 0; i < 4; i++) {
            auto [x, y] = p[value];
            int a = x + dx1[i], b = y + dy1[i];
            if (a >= 0 && a < n && b >= 0 && b < m) {
                s += g[a][b];
            }
        }
        return s;
    }

    int diagonalSum(int value) {
        int s = 0;
        for (int i = 0; i < 4; i++) {
            auto [x, y] = p[value];
            int a = x + dx2[i], b = y + dy2[i];
            if (a >= 0 && a < n && b >= 0 && b < m) {
                s += g[a][b];
            }
        }
        return s;
    }
};