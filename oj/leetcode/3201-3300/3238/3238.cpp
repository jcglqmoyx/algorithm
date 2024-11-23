#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>> &pick) {
        int cnt[n][11];
        memset(cnt, 0, sizeof cnt);
        for (auto &p: pick) {
            cnt[p[0]][p[1]]++;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 10; j++) {
                if (cnt[i][j] > i) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};