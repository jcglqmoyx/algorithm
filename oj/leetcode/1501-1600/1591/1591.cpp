#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPrintable(vector<vector<int>> &targetGrid) {
        auto n = targetGrid.size(), m = targetGrid[0].size();
        int pos[61][4];
        memset(pos, -1, sizeof pos);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = targetGrid[i][j];
                if (pos[x][0] == -1) {
                    q.emplace(x);
                }
                if (pos[x][0] == -1) {
                    pos[x][0] = i;
                }

                if (pos[x][1] == -1) {
                    pos[x][1] = j;
                } else {
                    pos[x][1] = min(pos[x][1], j);
                }

                pos[x][2] = i;
                pos[x][3] = max(pos[x][3], j);
            }
        }
        while (!q.empty()) {
            auto initial_size = q.size();
            for (auto it = initial_size; it; it--) {
                int t = q.front();
                q.pop();
                bool flag = true;
                vector<pair<int, int>> v;
                for (int i = pos[t][0]; i <= pos[t][2]; i++) {
                    for (int j = pos[t][1]; j <= pos[t][3]; j++) {
                        if (targetGrid[i][j]) {
                            if (targetGrid[i][j] != t) {
                                flag = false;
                            } else {
                                v.emplace_back(i, j);
                                targetGrid[i][j] = 0;
                            }
                        }
                    }
                }
                if (!flag) {
                    q.emplace(t);
                    for (auto [x, y]: v) {
                        targetGrid[x][y] = t;
                    }
                }
            }
            if (q.size() == initial_size) {
                return false;
            }
        }
        return true;
    }
};