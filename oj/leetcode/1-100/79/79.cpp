#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool exist(vector<vector<char>> &board, string word) {
        size_t n = board.size(), m = board[0].size();
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        bool st[n][m];
        memset(st, false, sizeof st);
        function<bool(int, int, int)> dfs = [&](int r, int c, int u) -> bool {
            if (u == word.size()) return true;
            if (r < 0 || r == n || c < 0 || c == m || board[r][c] != word[u] || st[r][c]) return false;
            st[r][c] = true;
            for (int i = 0; i < 4; i++) {
                int x = r + dx[i], y = c + dy[i];
                if (dfs(x, y, u + 1)) return true;
            }
            st[r][c] = false;
            return false;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j, 0)) return true;
            }
        }
        return false;
    }
};
