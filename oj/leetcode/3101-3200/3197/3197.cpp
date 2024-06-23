#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int INF = 100;

    int area(vector<vector<int>> &g, int start_row, int end_row, int start_col, int end_col) {
        int min_row = INF, max_row = 0, min_col = INF, max_col = 0;
        for (int i = start_row; i <= end_row; i++) {
            for (int j = start_col; j <= end_col; j++) {
                if (g[i][j]) {
                    min_row = min(min_row, i);
                    min_col = min(min_col, j);
                    max_row = max(max_row, i);
                    max_col = max(max_col, j);
                }
            }
        }
        if (min_row == INF) {
            return 0;
        }
        return (max_row - min_row + 1) * (max_col - min_col + 1);
    }

public:
    int minimumSum(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int res = n * m;
        for (int i = 0; i < n - 1; i++) {
            int top = area(grid, 0, i, 0, m - 1);
            if (top == 0) continue;
            for (int j = 0; j < m - 1; j++) {
                int bottom_left = area(grid, i + 1, n - 1, 0, j);
                if (bottom_left == 0) continue;
                int bottom_right = area(grid, i + 1, n - 1, j + 1, m - 1);
                if (bottom_right == 0) continue;
                res = min(res, top + bottom_left + bottom_right);
            }
        }
        for (int i = n - 1; i >= 1; i--) {
            int bottom = area(grid, i, n - 1, 0, m - 1);
            if (bottom == 0) continue;
            for (int j = 0; j < m - 1; j++) {
                int top_left = area(grid, 0, i - 1, 0, j);
                if (top_left == 0) continue;
                int top_right = area(grid, 0, i - 1, j + 1, m - 1);
                if (top_right == 0) continue;
                res = min(res, bottom + top_left + top_right);
            }
        }
        for (int j = 0; j < m - 1; j++) {
            int left = area(grid, 0, n - 1, 0, j);
            if (left == 0) continue;
            for (int i = 0; i < n - 1; i++) {
                int top_right = area(grid, 0, i, j + 1, m - 1);
                if (top_right == 0) continue;
                int bottom_right = area(grid, i + 1, n - 1, j + 1, m - 1);
                if (bottom_right == 0) continue;
                res = min(res, left + top_right + bottom_right);
            }
        }
        for (int j = m - 1; j >= 1; j--) {
            int right = area(grid, 0, n - 1, j, m - 1);
            if (right == 0) continue;
            for (int i = 0; i < n - 1; i++) {
                int top_left = area(grid, 0, i, 0, j - 1);
                if (top_left == 0) continue;
                int bottom_left = area(grid, i + 1, n - 1, 0, j - 1);
                if (bottom_left == 0) continue;
                res = min(res, right + top_left + bottom_left);
            }
        }
        for (int i = 0; i < n - 2; i++) {
            int top = area(grid, 0, i, 0, m - 1);
            if (top == 0) continue;
            for (int j = i + 1; j < n - 1; j++) {
                int middle = area(grid, i + 1, j, 0, m - 1);
                if (middle == 0) continue;
                int bottom = area(grid, j + 1, n - 1, 0, m - 1);
                if (bottom == 0) continue;
                res = min(res, top + middle + bottom);
            }
        }
        for (int i = 0; i < m - 2; i++) {
            int left = area(grid, 0, n - 1, 0, i);
            if (left == 0) continue;
            for (int j = i + 1; j < m - 1; j++) {
                int middle = area(grid, 0, n - 1, i + 1, j);
                if (middle == 0) continue;
                int right = area(grid, 0, n - 1, j + 1, m - 1);
                if (right == 0) continue;
                res = min(res, left + middle + right);
            }
        }
        return res;
    }
};