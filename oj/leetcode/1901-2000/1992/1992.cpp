#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land) {
        auto n = land.size(), m = land[0].size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j]) {
                    res.push_back({i, j});
                    int x = i, y = j;
                    while (true) {
                        if (x + 1 < n && land[x + 1][y]) x++;
                        else if (y + 1 < m && land[x][y + 1]) y++;
                        else break;
                    }
                    res.back().emplace_back(x);
                    res.back().emplace_back(y);
                    for (int a = i; a <= x; a++) {
                        for (int b = j; b <= y; b++) {
                            land[a][b] = 0;
                        }
                    }
                }
            }
        }
        return res;
    }
};