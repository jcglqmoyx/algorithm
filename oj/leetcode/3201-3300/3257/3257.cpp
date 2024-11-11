#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<vector<int>> &board) {
        using ll = long long;
        auto n = board.size(), m = board[0].size();
        auto U = board, D = board;
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                U[i][j] = max(U[i][j], U[i - 1][j]);
            }
            for (int i = n - 2; i >= 0; i--) {
                D[i][j] = max(D[i][j], D[i + 1][j]);
            }
        }
        pair<ll, int> pre[n][3], suf[n][3];
        memset(pre, -0x3f, sizeof pre), memset(suf, -0x3f, sizeof suf);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (U[i][j] > pre[i][0].first) {
                    pre[i][2].first = pre[i][1].first;
                    pre[i][2].second = pre[i][1].second;
                    pre[i][1].first = pre[i][0].first;
                    pre[i][1].second = pre[i][0].second;
                    pre[i][0].first = U[i][j];
                    pre[i][0].second = j;
                } else if (U[i][j] > pre[i][1].first) {
                    pre[i][2].first = pre[i][1].first;
                    pre[i][2].second = pre[i][1].second;
                    pre[i][1].first = U[i][j];
                    pre[i][1].second = j;
                } else if (U[i][j] > pre[i][2].first) {
                    pre[i][2].first = U[i][j];
                    pre[i][2].second = j;
                }
                if (D[i][j] > suf[i][0].first) {
                    suf[i][2].first = suf[i][1].first;
                    suf[i][2].second = suf[i][1].second;
                    suf[i][1].first = suf[i][0].first;
                    suf[i][1].second = suf[i][0].second;
                    suf[i][0].first = D[i][j];
                    suf[i][0].second = j;
                } else if (D[i][j] > suf[i][1].first) {
                    suf[i][2].first = suf[i][1].first;
                    suf[i][2].second = suf[i][1].second;
                    suf[i][1].first = D[i][j];
                    suf[i][1].second = j;
                } else if (D[i][j] > suf[i][2].first) {
                    suf[i][2].first = D[i][j];
                    suf[i][2].second = j;
                }
            }
        }
        ll res = INT64_MIN;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                for (int a = 0; a < 3; a++) {
                    if (pre[i - 1][a].second == j) continue;
                    for (int b = 0; b < 3; b++) {
                        if (suf[i + 1][b].second == j || suf[i + 1][b].second == pre[i - 1][a].second) continue;
                        res = max(res, pre[i - 1][a].first + suf[i + 1][b].first + board[i][j]);
                    }
                }
            }
        }
        return res;
    }
};