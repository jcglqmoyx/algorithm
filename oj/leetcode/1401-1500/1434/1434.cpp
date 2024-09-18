#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberWays(vector<vector<int>> &hats) {
        auto n = hats.size();
        int m = 1e9 + 7;
        int max_hat_id = 0;
        for (auto &h: hats) {
            for (int id: h) {
                max_hat_id = max(max_hat_id, id);
            }
        }
        vector<vector<int>> hat_to_person(max_hat_id + 1);
        for (int i = 0; i < n; i++) {
            for (int id: hats[i]) {
                hat_to_person[id].emplace_back(i);
            }
        }
        int f[2][1 << n];
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= max_hat_id; i++) {
            for (int j = 0; j < 1 << n; j++) {
                f[i & 1][j] = f[i & 1 ^ 1][j];
                for (int id: hat_to_person[i]) {
                    if (j >> id & 1) {
                        f[i & 1][j] = f[i & 1][j] + f[i & 1 ^ 1][j ^ (1 << id)];
                        if (f[i & 1][j] > m) f[i & 1][j] -= m;
                    }
                }
            }
        }
        return f[max_hat_id & 1][(1 << n) - 1];
    }
};